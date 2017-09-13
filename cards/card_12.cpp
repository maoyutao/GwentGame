#include "card_12.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"


Card_12::Card_12(BattleField *battleField, QObject *parent):
    Card(12, 5, "Woodland Spirit", "部署：生成 3 只“暴怒的狼”，并在对方同排降下“蔽日浓雾”。",
         ":/new/cards/resource/cards/card_12.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Beast);
}

void Card_12::exertAbility()
{

}

