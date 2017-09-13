#include "card_13.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_13::Card_13(BattleField *battleField, QObject *parent):
    Card(13, 6, "Earth Elemental", "部署：获得护盾。遗愿：在该排末位生成 2 个“次级土元素”。",
         ":/new/cards/resource/cards/card_13.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    property.append(EProperty::Tectosome);
}

void Card_13::exertAbility()
{


}
