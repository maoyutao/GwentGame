#include "w_edit.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>

Edit::Edit(QWidget *parent) : QStackedWidget(parent)
{

}

void Edit::init(Player *player, Ui::MainWindow *aui)
{
    ui = aui;
    mplayer = player;
    this->setCurrentIndex(0);
    ui->cardSet->setLimit(3);
    CardSetButton* newSet = new CardSetButton(nullptr, ui->cardSet);
    CardSetButton* newSet1 = new CardSetButton(nullptr, ui->cardSet);
    CardSetButton* newSet2 = new CardSetButton(nullptr, ui->cardSet);
    CardSetButton* newSet3 = new CardSetButton(nullptr, ui->cardSet);
    CardSetButton* newSet4 = new CardSetButton(nullptr, ui->cardSet);
    CardSetButton* newSet5 = new CardSetButton(nullptr, ui->cardSet);
    ui->cardSet->addCard(newSet);
//    ui->cardSet->addCard(newSet1);
//    ui->cardSet->addCard(newSet2);
//    ui->cardSet->addCard(newSet3);
//    ui->cardSet->addCard(newSet4);
//    ui->cardSet->addCard(newSet5);
    for (auto it: mplayer->cardSets)
    {
        CardSetButton* set = new CardSetButton(&*it, ui->cardSet);
        cardSetList.append(&*it); // 每new都要保存指针
        ui->cardSet->addCard(set); // 显示
    }
    qDebug() << cardSetList.at(0)->name;
    for (int i = 0; i < ui->cardSet->currentWidget()->layout()->count(); i++)
    {
//        qDebug() << ui->cardSet->currentWidget()->layout()->itemAt(i)->widget();
    }
}

void Edit::clear()
{
    ui->cardSet->clear();
}
