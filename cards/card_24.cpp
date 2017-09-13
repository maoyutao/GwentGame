#include "card_24.h"
#include "w_battlefield.h"
#include "ui_cardslot.h"

Card_24::Card_24(BattleField *battleField, QObject *parent):
    Card(24, 0, "晴空", "移除己方半场所有的天气效果。”。", ":/new/cards/resource/cards/card_24.png", EQuality::Copper,
         EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Special);
    property.append(EProperty::Strategy);
    property.append(EProperty::Weather);
}

void Card_24::exertAbility()
{
    for (int i = 3; i < 6; i++)
    {
        battleField->cardSlot[i]->clearSpecialCard();
    }
    if (first)
    {
        emit battleField->finishOneRound();
    }
    first = false;
    emit battleField->clearChooseSlot();
}
