#include "card_3.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"
#include <QTime>
#include <QtGlobal>

Card_3::Card_3(BattleField *battleField, QObject *parent):
    Card(3, 0, "Torrential Rain", "在对方单排降下“倾盆大雨”。倾盆大雨：每当己方回合开始时，对所在排最多 2 个随机单位造成 1 点伤害。", ":/new/cards/resource/cards/card_3.png",
         EQuality::Copper, EClassification::Event, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);
    property.append(EProperty::Special);
    property.append(EProperty::Weather);
}

void Card_3::exertAbility()
{
    if (first)
    {
        battleField->setAllHandCardExertable(false);
        QList<int> positon;
        positon << SLOTOBACK << SLOTOFRONT << SLOTOMMIDLE;
        choosePosition(positon);
        first = false;
        return;
    }
    if (mslot->cardList.empty())
    {
        return;
    }
    int total = mslot->cardList.count();
    if (total == 1)
    {
        battleField->changeStrenth(-1, dynamic_cast<CardButton*>(mslot->cardList.first()));
        return;
    }
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int index1 = qrand() % total;
    battleField->changeStrenth(-1, dynamic_cast<CardButton*>(mslot->cardList.at(index1)));
    int index2 = index1;
    while (index2 == index1)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        index2 = qrand() % total;
    }
    battleField->changeStrenth(-1, dynamic_cast<CardButton*>(mslot->cardList.at(index2)));
}

void Card_3::afterChoosePosition(CardSlot* slot)
{
    basicAfterChoosePosition();
    battleField->changeSpecialCard(slot, "add", button);
    mslot = slot;
    battleField->move(nullptr, button);
    emit battleField->finishOneRound();
}
