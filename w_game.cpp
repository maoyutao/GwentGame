#include "w_game.h"
#include "ui_mainwindow.h"
#include "ui_standarddialog.h"
#include "cardset.h"
#include <QStringList>
#include <QDialog>
#include <QDebug>
#include <QtNetwork>
#include <QStringBuilder>

#define PGAMEREADY 0
#define PWAITING 1
#define PCHOOSE 2
#define PGAMING 3
#define PSCORE 4
#define PFINALSCORE 5

Game::Game(QWidget *parent) : QStackedWidget(parent)
{

}

void Game::init(Player *aPlayer, Ui::MainWindow *aui)
{
    ui = aui;
    player = aPlayer;
    this->setCurrentIndex(PGAMEREADY);
    qDebug() << this->currentWidget()->styleSheet();
    connect(ui->asClientButton, SIGNAL(clicked()), this, SLOT(asClient()), Qt::UniqueConnection);
    connect(ui->asServerButton, SIGNAL(clicked()), this, SLOT(asServer()), Qt::UniqueConnection);
}

void Game::asClient()
{
    Dialog dlg("invitation code:", true, this);
    if (QDialog::Accepted == dlg.exec())
    {
        this->setCurrentIndex(PWAITING);
        QStringList list = dlg.content.split('&');
        QHostAddress address = QHostAddress(list.at(0));
        int port = list.at(1).toInt();
        socket = new QTcpSocket(this);
        socket->connectToHost(address, port, QTcpSocket::ReadWrite);
        connect(socket, SIGNAL(connected()), this, SLOT(onConnect()));
    }
}

void Game::asServer()
{
    QHostAddress ip;
    int port = 56700;
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address, info.addresses())
    {
         if(address.protocol() == QAbstractSocket::IPv4Protocol)
         {
             ip = address;
             break;
         }
    }
    server = new QTcpServer(this);
    while (!server->listen(ip, port))
    {
        port++;
    }
    connect(server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    Dialog dlg("invitation code:", true, this);
    dlg.setText(ip.toString() % "&" % QString::number(port));
    if (QDialog::Accepted == dlg.exec())
    {
        this->setCurrentIndex(PWAITING);
    }
    else
    {
        server->close();
        server->deleteLater();
    }
}

void Game::onConnect()
{
    ui->msg->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; color:#b7b7b7;\">Connect successfully!</span></p></body></html>", Q_NULLPTR));
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(chooseCardSet()), Qt::UniqueConnection);
    connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()), Qt::UniqueConnection);
    timer->start(1200);
}

void Game::onNewConnection()
{
    if (this->currentIndex() != PWAITING)
    {
        for (auto it: this->children())
        {
            qDebug() << &*it;
            if (it->inherits("Dialog"))
            {
                static_cast<Dialog*>(*&it)->accept();
            }
        }
        this->setCurrentIndex(PWAITING);
    }
    socket = server->nextPendingConnection();
    onConnect();
}

void Game::chooseCardSet()
{
    qDebug() << "choose";
    ui->gamingChooseSlot->setLimit(3); // 设置一页最多几张
    for (auto it: player->cardSets)
    {
        qDebug() << "createSetButton";
        CardSetButton* set = new CardSetButton(&*it, ui->gamingChooseSlot); // 实例化按钮
        ui->gamingChooseSlot->addCard(set); // 显示
        if (it->isValid) {
            connect(set, SIGNAL(seletced(CardSet*)), this, SLOT(start(CardSet*)));
        } else {
            set->setEnabled(false);
        }
    }
    this->setCurrentIndex(PCHOOSE);
}

void Game::start(CardSet *cardSet)
{
    ui->msg->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; color:#b7b7b7;\">Please wait patiently.</span></p></body></html>", Q_NULLPTR));
    this->setCurrentIndex(PWAITING);
    ui->gamingChooseSlot->clear();
    ui->battleField->init(cardSet, ui);
}
