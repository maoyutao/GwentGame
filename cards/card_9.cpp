#include "card_9.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_9::Card_9(BattleField *battleField, QObject *parent):
    Card(9, 4, "Foglet", "每当己方“蔽日浓雾”在敌排生效，便从牌组打出 1 个“小雾妖”至己方同排。若牌组中没有“小雾妖”，则复活 1 个“小雾妖”至己方同排。若场上不再存在“蔽日浓雾”效果，则摧毁所有“小雾妖”。",
         ":/new/cards/resource/cards/card_9.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Scavengers);
}

void Card_9::exertAbility()
{


}

