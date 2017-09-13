#include "card_21.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_21::Card_21(BattleField *battleField, QObject *parent):
    Card(21, 3, "Arachas", "部署：从牌组打出所有“蟹蜘蛛”。",
         ":/new/cards/resource/cards/card_21.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Worm);
}

void Card_21::exertAbility()
{


}
