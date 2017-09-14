#include "card_1.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"
#include <QDebug>

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
        battleField->setAllHandCardExertable(false);
        QList<int> positon;
        positon << SLOTOBACK << SLOTOFRONT << SLOTOMMIDLE;
        choosePosition(positon);
        first = false;
        return;
    }
    flag++;
    if (flag % 2)
    {
        if (mslot->cardList.empty())
        {
            return;
        }
        CardButton* but;
        int strenth = -1;
        for (auto it: mslot->cardList)
        {
            CardButton* i = dynamic_cast<CardButton*>(it);
            int v = i->card->currentCombatValue;
            if ((strenth == -1) || v < strenth)
            {
                but = i;
                strenth = v;
            }
        }
        battleField->changeStrenth(-2, but);
    }
}

void Card_1::afterChoosePosition(CardSlot* slot)
{
    qDebug() << "afterChoosePosition";
    basicAfterChoosePosition();
    battleField->changeSpecialCard(slot, "add", button);
    mslot = slot;
    battleField->move(nullptr, button);
    emit battleField->finishOneRound();
}
