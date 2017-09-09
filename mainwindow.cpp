#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_cardbutton.h"
#include <QMetaObject>
#include <QDebug>
#include <QFont>

#define PStartIndex 0
#define PChooseIndex 1
#define PEditIndex 2
#define PPlayIndex 3

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mPlayer(new Player(this))
{
    ui->setupUi(this);
    ui->start->installEventFilter(this);
    ui->finalScore->installEventFilter(this);
//    qDebug() << CardFactory::cardMap;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mPlayer;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::KeyPress || event->type() == QEvent::MouseButtonPress)
    {
        QStackedWidget *stackWidget = ui->mainStackedWidget;
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
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::on_toEditCard_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(PEditIndex);
}

void MainWindow::on_returnToChoose_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(PChooseIndex);
}

void MainWindow::on_toPlay_clicked()
{
    ui->mainStackedWidget->setCurrentIndex(PPlayIndex);
}


//void MainWindow::on_cardSet_2_clicked()
//{
//    ui->mainStackedWidget->setCurrentIndex(PEditCardsIndex);
//    Card * card0 = static_cast<Card*>(CardFactory::CreateObject(0, game->battleField, game->battleField));
//    CardButton *card0but = new CardButton(card0, ui->editCardBackPage1);
//    Card * card1 = static_cast<Card*>(CardFactory::CreateObject(1, game->battleField, game->battleField));
//    CardButton *card1but = new CardButton(card1, ui->editCardFrontPage1);
//    Card * card2 = static_cast<Card*>(CardFactory::CreateObject(2, game->battleField, game->battleField));
//    CardButton *card2but = new CardButton(card1, ui->editCardFrontPage1);
//    Card * card3 = static_cast<Card*>(CardFactory::CreateObject(3, game->battleField, game->battleField));
//    CardButton *card3but = new CardButton(card3, ui->editCardBackPage1);
//    Card * card4 = static_cast<Card*>(CardFactory::CreateObject(4, game->battleField, game->battleField));
//    CardButton *card4but = new CardButton(card4, ui->editCardMiddlePage1);
//    CardButton *card5but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card6but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card7but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card8but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card9but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card10but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card11but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card14but = new CardButton(card4, ui->editCardMiddlePage1);
//    CardButton *card15but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card16but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card17but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card18but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card19but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card20but = new CardButton(card4, ui->editCardFrontPage1);
//    CardButton *card21but = new CardButton(card4, ui->editCardFrontPage1);
//    ui->editCardFront->addCard(card1but);
//    ui->editCardFront->addCard(card0but);
//    ui->editCardFront->addCard(card2but);
//    ui->editCardFront->addCard(card3but);
//    ui->editCardFront->addCard(card4but);
//    ui->editCardFront->addCard(card5but);
//    ui->editCardFront->addCard(card6but);
//    ui->editCardFront->addCard(card7but);
//    ui->editCardFront->addCard(card8but);
//    ui->editCardFront->addCard(card9but);
//    ui->editCardFront->addCard(card10but);
//    ui->editCardFront->addCard(card11but);
//    ui->editCardFront->addCard(card14but);
//    ui->editCardFront->addCard(card15but);
//    ui->editCardFront->addCard(card16but);
//    ui->editCardFront->addCard(card17but);
//    ui->editCardFront->addCard(card18but);
//    ui->editCardFront->addCard(card19but);
//    ui->editCardFront->addCard(card20but);
//    ui->editCardFront->addCard(card21but);
//    ui->editCardFrontPage1->addCard(card1but, 0);
//    ui->editCardFrontPage1->addCard(card2but, 1);
//    ui->editCardFrontPage1->addPage();
//    ui->editCardBackPage1->mlayout->addWidget(card3but, 0, Qt::AlignCenter);
//    ui->editCardMiddlePage1->mlayout->addWidget(card4but, 0, Qt::AlignCenter);
//    ui->editCardALLPage1->mlayout->addWidget(card5but, 0, Qt::AlignTop);
//    ui->editCardALLPage1->mlayout->addWidget(card6but, 0, Qt::AlignTop);
//}

