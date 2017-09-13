#include "card_19.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_19::Card_19(BattleField *battleField, QObject *parent):
    Card(19, 12, "Frightener", "佚亡。部署：从牌组顶端抽 1 张牌。将所在战场其他排的 1 个单位移至自身的同一排。",
         ":/new/cards/resource/cards/card_19.png",
         EQuality::Silver, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);
    property.append(EProperty::Spy);
    property.append(EProperty::Tectosome);
}

void Card_19::exertAbility()
{


}
