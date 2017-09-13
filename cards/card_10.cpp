#include "card_10.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_10::Card_10(BattleField *battleField, QObject *parent):
    Card(10, 1, "Ge'els", "部署：从牌组顶端各抽 1 张金色牌和银色牌。打出 1 张，将另 1 张置于牌组顶端。",
         ":/new/cards/resource/cards/card_10.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Officer);
    property.append(EProperty::WildHunt);
}

void Card_10::exertAbility()
{

}
