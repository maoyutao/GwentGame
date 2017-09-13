#include "card_18.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"


Card_18::Card_18(BattleField *battleField, QObject *parent):
    Card(18, 8, "Caranthir", "部署：将 1 个敌军单位移至其所在半场同排，并在此排降下“刺骨冰霜”。",
         ":/new/cards/resource/cards/card_18.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::WildHunt);
}

void Card_18::exertAbility()
{

}
