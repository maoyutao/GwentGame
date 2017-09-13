#include "card_2.h"


Card_2::Card_2(BattleField *battleField, QObject *parent):
    Card(2, 0, "Impenetrable Fog", "在对方单排降下“蔽日浓雾”。蔽日浓雾：每当己方回合开始时，对所在排最强的单位造成 2 点伤害。", ":/new/cards/resource/cards/card_2.png",
         EQuality::Copper, EClassification::Event, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);
    property.append(EProperty::Special);
    property.append(EProperty::Weather);
}

void Card_2::exertAbility()
{

}
