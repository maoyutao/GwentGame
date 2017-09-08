#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_cardbutton.h"
#include <QMetaObject>
#include <QDebug>
#include <QFont>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->start->installEventFilter(this);
    ui->finalScore->installEventFilter(this);
    qDebug() << CardFactory::cardMap;

    mPlayer = new Player(this);
    game = new Game(mPlayer, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched->parent() == ui->stackedWidget)
    {
        if (event->type() == QEvent::KeyPress || event->type() == QEvent::MouseButtonPress)
        {
            QStackedWidget *stackWidget = static_cast<QStackedWidget*>(watched->parent());
            int index = stackWidget->currentIndex();
            int count = stackWidget->count();
            index++;
            if (index >= count)
            {
                index = 0;
            }
            stackWidget->setCurrentIndex(index);
            return true;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::on_toEditCard_clicked()
{
    ui->stackedWidget->setCurrentIndex(PChooseEditCcardsIndex);
}

void MainWindow::on_returnToChoose_clicked()
{
    ui->stackedWidget->setCurrentIndex(PChooseIndex);
}

void MainWindow::on_cardSet_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(PEditCardsIndex);
    Card * card0 = static_cast<Card*>(CardFactory::CreateObject(0, game->battleField, game->battleField));
    CardButton *card0but = new CardButton(card0, ui->editCardBackSlot1);
    Card * card1 = static_cast<Card*>(CardFactory::CreateObject(1, game->battleField, game->battleField));
    CardButton *card1but = new CardButton(card1, ui->editCardFrontSlot1);
    Card * card2 = static_cast<Card*>(CardFactory::CreateObject(2, game->battleField, game->battleField));
    CardButton *card2but = new CardButton(card2, ui->editCardFrontSlot1);
    Card * card3 = static_cast<Card*>(CardFactory::CreateObject(3, game->battleField, game->battleField));
    CardButton *card3but = new CardButton(card3, ui->editCardFrontSlot1);
    Card * card4 = static_cast<Card*>(CardFactory::CreateObject(4, game->battleField, game->battleField));
    CardButton *card4but = new CardButton(card4, ui->editCardFrontSlot1);
    Card * card5 = static_cast<Card*>(CardFactory::CreateObject(5, game->battleField, game->battleField));
    CardButton *card5but = new CardButton(card4, ui->editCardFrontSlot1);
    ui->editCardFrontSlot1->mlayout->addWidget(card0but, 0, Qt::AlignHCenter);
    ui->editCardFrontSlot1->mlayout->addWidget(card1but, 0, Qt::AlignHCenter);
    ui->editCardFrontSlot1->mlayout->addWidget(card2but, 0, Qt::AlignHCenter);
    ui->editCardFrontSlot1->mlayout->addWidget(card3but, 0, Qt::AlignHCenter);
    ui->editCardFrontSlot1->mlayout->addWidget(card4but, 0, Qt::AlignHCenter);
    ui->editCardFrontSlot1->mlayout->addWidget(card5but, 0, Qt::AlignHCenter);
}

void MainWindow::on_cardSet_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(PEditCardsIndex);
    // todo
}

void MainWindow::on_newCardSet_clicked()
{
    ui->stackedWidget->setCurrentIndex(PEditCardsIndex);
    // todo
}
