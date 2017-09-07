#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    // todo
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
