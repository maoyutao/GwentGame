#include "card_25.h"
#include "w_battlefield.h"
#include "ui_cardslot.h"

Card_25::Card_25(BattleField *battleField, QObject *parent):
    Card(25, 0, "重整", "从牌组打出1张随机铜色单位牌。", ":/new/cards/resource/cards/card_25.png", EQuality::Copper,
         EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Special);
    property.append(EProperty::Strategy);
    property.append(EProperty::Weather);
}


void Card_25::exertAbility()
{
    battleField->drawCards(1).first()->card->exertAbility();
}
