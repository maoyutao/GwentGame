#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_cardbutton.h"
#include "cardfactory.h"
#include <QMetaObject>
#include <QDebug>
#include <QFont>

#define PSTART 0
#define PCHOOSE 1
#define PEDIT 2
#define PGAME 3

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mPlayer(new Player(this))
{
    ui->setupUi(this);
    ui->start->installEventFilter(this);
    ui->finalScore->installEventFilter(this);
    ui->mainStackedWidget->setCurrentIndex(PSTART);
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
    ui->editStackWidget->init(mPlayer, ui);
    ui->mainStackedWidget->setCurrentIndex(PEDIT);
}

void MainWindow::on_returnToChoose_clicked()
{
    ui->editStackWidget->clear();
    ui->mainStackedWidget->setCurrentIndex(PCHOOSE);
}

void MainWindow::on_toPlay_clicked()
{
    ui->gameStackWidget->init(mPlayer, ui);
    ui->mainStackedWidget->setCurrentIndex(PGAME);
}
