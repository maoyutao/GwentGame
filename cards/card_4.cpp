#include "card_4.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"


Card_4::Card_4(BattleField *battleField, QObject *parent):
    Card(4, 0, "Lacerate", "对单排所有单位造成 3 点伤害。", ":/new/cards/resource/cards/card_4.png",
        EQuality::Copper, EClassification::Event, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);
    property.append(EProperty::Organisms);
    property.append(EProperty::Special);
}

void Card_4::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    QList<int> positon;
    positon << SLOTOBACK << SLOTOFRONT << SLOTOMMIDLE;
    choosePosition(positon);

}

void Card_4::afterChoosePosition(CardSlot *slot)
{
    basicAfterChoosePosition();
    for (auto it: slot->cardList)
    {
        battleField->changeStrenth(-3, dynamic_cast<CardButton*>(it));
    }
    battleField->move(nullptr, button);
    emit battleField->finishOneRound();
}

