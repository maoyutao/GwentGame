#include "w_edit.h"
#include "ui_mainwindow.h"
#include "ui_standarddialog.h"
#include "cardfactory.h"
#include <QDebug>
#include <QHBoxLayout>


Edit::Edit(QWidget *parent) : QStackedWidget(parent)
{
}

void Edit::init(Player *player, Ui::MainWindow *aui)
{
    ui = aui;
    mplayer = player;
    clear();
    connect(ui->returnToChooseEditCards, SIGNAL(clicked()), this, SLOT(returnToChoose()), Qt::UniqueConnection);
    this->setCurrentIndex(0);
    ui->cardSet->setLimit(3); // 设置一页最多几张
    CardSetButton* newSet = new CardSetButton(nullptr, nullptr); // 新建牌组的选项
    connect(newSet, SIGNAL(seletced(CardSet*)), this, SLOT(enterEdit(CardSet*)));
    ui->cardSet->addCard(newSet); // 显示
    for (auto it: mplayer->cardSets)
    {
        CardSetButton* set = new CardSetButton(&*it, nullptr); // 实例化按钮
        cardSetList.append(&*it); // 每new都要保存指针
        connect(set, SIGNAL(seletced(CardSet*)), this, SLOT(enterEdit(CardSet*)));// 连接  结束的时候按钮都没了所以不用disconnect
        ui->cardSet->addCard(static_cast<QPushButton*>(set)); // 显示
    }
}

void Edit::clear()
{
    ui->cardSet->clear();
    ui->editCardALL->clear();
    ui->editCardBack->clear();
    ui->editCardEvent->clear();
    ui->editCardFront->clear();
    ui->editCardMiddle->clear();
    cardList.clear();
    cardSetList.clear();
    currentSet = nullptr;
    tempSet.clear();
}

void Edit::enterEdit(CardSet * cardSet)
{
    ui->cardSet->clear();
    if (!cardSet)
    {
        QString name;
        Dialog dlg("name:", true, this);
        if (QDialog::Accepted == dlg.exec())
        {
            name = dlg.content;
        } else {
            return;
        }
        currentSet = new CardSet(name);
        mplayer->cardSets.append(currentSet);
        this->setCurrentIndex(1);
        return;
    }
    QList<int> tempAll = cardSet->allCards;
    QList<int> tempM;
    QList<int> tempF;
    QList<int> tempB;
    QList<int> tempE;
    for (auto card: cardSet->allCards) // 卡组里的卡要显示到上方
    {
        tempAll.removeOne(card);
        Card* mcard = static_cast<Card*>(CardFactory::CreateObject(card, nullptr, nullptr));
        switch(mcard->position.at(0))
        {
        case EPosition::mBack:
        case EPosition::oBack:
            tempB.append(card);
            break;
        case EPosition::mFront:
        case EPosition::oFront:
            tempF.append(card);
            break;
        case EPosition::mMiddle:
        case EPosition::oMiddle:
            tempM.append(card);
            break;
        case EPosition::Null:
            tempE.append(card);
            break;
        }
        delete mcard;
    }
    QList<QPushButton*> tempCardList;
    for (auto it: tempAll)
    {
        CardButton* card = new CardButton(it, nullptr, nullptr);
        tempCardList.append(static_cast<QPushButton*>(card));
        cardList.append(card); // 全部的卡（的按钮）都实例化 存在cardlist里
        connect(card, SIGNAL(seletced(CardButton*)), this, SLOT(addToSet(CardButton*)));
    }
    ui->editCardALL->addCard(tempCardList);
    tempCardList.clear();
    for (auto it: tempF)
    {
        CardButton* card = new CardButton(it, nullptr, nullptr);
        tempCardList.append(card);
        cardList.append(card); // 全部的卡（的按钮）都实例化 存在cardlist里
        connect(card, SIGNAL(seletced(CardButton*)), this, SLOT(addToSet(CardButton*)));
    }
    ui->editCardFront->addCard(tempCardList);
    tempCardList.clear();
    for (auto it: tempM)
    {
        CardButton* card = new CardButton(it, nullptr, nullptr);
        tempCardList.append(card);
        cardList.append(card); // 全部的卡（的按钮）都实例化 存在cardlist里
        connect(card, SIGNAL(seletced(CardButton*)), this, SLOT(addToSet(CardButton*)));
    }
    ui->editCardMiddle->addCard(tempCardList);
    tempCardList.clear();
    for (auto it: tempE)
    {
        CardButton* card = new CardButton(it, nullptr, nullptr);
        tempCardList.append(card);
        cardList.append(card); // 全部的卡（的按钮）都实例化 存在cardlist里
        connect(card, SIGNAL(seletced(CardButton*)), this, SLOT(addToSet(CardButton*)));
    }
    ui->editCardEvent->addCard(tempCardList);
    currentSet = cardSet;
    this->setCurrentIndex(1);
}

void Edit::addToSet(CardButton *card)
{
    disconnect(card, SIGNAL(seletced(CardButton*)), this, SLOT(addToSet(CardButton*)));
    connect(card, SIGNAL(seletced(CardButton*)), this, SLOT(removeFromSet(CardButton*)));
    tempSet.append(card->card->id);
    ui->editCardALL->removeCard(card);
    switch(card->card->position.at(0))
    {
    case EPosition::mBack:
    case EPosition::oBack:
        ui->editCardBack->addCard(card);
        break;
    case EPosition::mFront:
    case EPosition::oFront:
        ui->editCardFront->addCard(card);
        break;
    case EPosition::mMiddle:
    case EPosition::oMiddle:
        ui->editCardMiddle->addCard(card);
        break;
    case EPosition::Null:
        ui->editCardEvent->addCard(card);
        break;
    }
}

void Edit::removeFromSet(CardButton *card)
{
    disconnect(card, SIGNAL(seletced(CardButton*)), this, SLOT(removeFromSet(CardButton*)));
    connect(card, SIGNAL(seletced(CardButton*)), this, SLOT(addToSet(CardButton*)));
    tempSet.removeOne(card->card->id);
    static_cast<CardSlot*>(card->parentWidget()->parentWidget())->removeCard(card);
    ui->editCardALL->addCard(card);
}

void Edit::returnToChoose()
{
    Dialog dlg("save?", false, this);
    if (QDialog::Accepted == dlg.exec())
    {
        currentSet->allCards = tempSet;
    }
    init(mplayer, ui);
    this->setCurrentIndex(0);
}

