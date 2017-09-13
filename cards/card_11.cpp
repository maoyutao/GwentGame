#include "card_11.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_11::Card_11(BattleField *battleField, QObject *parent):
    Card(11, 5, "Celaeno Harpy", "部署：在自身左侧生成 2 个“鹰身女妖蛋”。",
         ":/new/cards/resource/cards/card_11.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Beast);
}

void Card_11::exertAbility()
{

}
