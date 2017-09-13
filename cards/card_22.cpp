#include "card_22.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_22::Card_22(BattleField *battleField, QObject *parent):
    Card(22, 6, "Vran Warrior", "部署：吞噬右侧单位。每 2 回合，己方回合开始时，吞噬右侧单位。",
         ":/new/cards/resource/cards/card_22.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Drake);
}

void Card_22::exertAbility()
{


}
