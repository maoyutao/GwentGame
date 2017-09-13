#include "card_17.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_17::Card_17(BattleField *battleField, QObject *parent):
    Card(17, 8, "Archgriffin", "部署：移除所在排的天气效果。将 1 张铜色牌从一方墓场置入另一方墓场",
         ":/new/cards/resource/cards/card_17.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Beast);
}

void Card_17::exertAbility()
{

}
