#include "card_1.h"

Card_1::Card_1(BattleField *battleField, QObject *parent):
    Card(1, 0, "Biting Frost", "在对方单排降下“刺骨冰霜”。刺骨冰霜：每当己方回合开始时，对所在排最弱的单位造成 2 点伤害。", ":/new/cards/resource/cards/card_1.png",
         EQuality::Copper,
         EClassification::Event, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);

    property.append(EProperty::Special);
    property.append(EProperty::Weather);
}

void Card_1::exertAbility()
{
    if (first)
    {
        for (int i = 0; i< 3; i++)
        {
            CardSlot* slot = battleField->cardSlot[i];
            slot->setChooseable(true);
            connect(slot, SIGNAL(selected(CardSlot*)), this, SLOT(afterChoosePosition(CardSlot)));
        }
        first = false;
        return;
    }
    flag++;
    if (flag % 2)
    {
        CardButton* but;
        int strenth = -1;
        for (CardButton* it: mslot->cardList)
        {
            int v = it->card->currentCombatValue;
            if ((strenth == -1) || v < strenth)
            {
                but = it;
                strenth = v;
            }
        }
        battleField->changeStrenth(-2, but);
    }
}

void Card_1::afterChoosePosition(CardSlot* slot)
{
    for (int i = 0; i< 3; i++)
    {
        CardSlot* slott = battleField->cardSlot[i];
        slott->setChooseable(false);
        disconnect(slott, SIGNAL(selected(CardSlot*)), this, SLOT(afterChoosePosition(CardSlot)));
    }
    battleField->changeSpecialCard(slot, "add", button);
    mslot = slot;
    battleField->move(nullptr, button);
    emit battleField->finishOneRound();
}
