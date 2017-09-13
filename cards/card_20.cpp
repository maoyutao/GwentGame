#include "card_20.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_20::Card_20(BattleField *battleField, QObject *parent):
    Card(20, 5, "Unseen Elder", "佚亡、坚守。部署：吞噬 3 个友军单位，吸收它们的战力为自身的基础战力。",
         ":/new/cards/resource/cards/card_20.png",
         EQuality::Gold, EClassification::Leader, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Vampire);
}

void Card_20::exertAbility()
{


}
