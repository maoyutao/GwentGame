#include "card_23.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_23::Card_23(BattleField *battleField, QObject *parent):
    Card(23, 6, "Arachas Behemoth", "每当有友军单位吞噬 1 张牌，便生成 1 只“蟹蜘蛛幼虫”，随后受到 1 点伤害（无视护甲）。部署：获得 2 点护甲。",
         ":/new/cards/resource/cards/card_23.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Worm);
}

void Card_23::exertAbility()
{


}
