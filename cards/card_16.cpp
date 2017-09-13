#include "card_16.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_16::Card_16(BattleField *battleField, QObject *parent):
    Card(16, 8, "Crone: Brewess", "部署：从牌组打出“呢喃婆”和“织婆”。",
         ":/new/cards/resource/cards/card_16.png",
         EQuality::Silver, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::Waste);
}

void Card_16::exertAbility()
{

}
