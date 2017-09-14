#include "card_7.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_7::Card_7(BattleField *battleField, QObject *parent):
    Card(7, 5, "Geralt: Igni", "部署：若对方同排总战力不低于 25 ，则摧毁其上所有最强的单位。", ":/new/cards/resource/cards/card_7.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Hunter);
}

void Card_7::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    QList<int> positon;
    positon << SLOTMBACK << SLOTMFRONT << SLOTMMMIDLE;
    choosePosition(positon);
}

void Card_7::afterChoosePosition(CardSlot *slot)
{
    basicAfterChoosePosition();
    battleField->move(slot, button);
    int sindex = battleField->cardSlot.indexOf(slot);
    sindex = 5 - sindex;
    CardSlot* oslot = battleField->cardSlot.at(sindex);
    if (battleField->strenth[oslot] >= 25)
    {
        if (oslot->cardList.empty())
        {
            return;
        }
        int max = -1;
        int strenth;
        for (auto i: oslot->cardList)
        {
            CardButton* it = dynamic_cast<CardButton*>(i);
            strenth = it->card->currentCombatValue;
            if ((max == -1) || (strenth > max))
            {
                max = strenth;
            }
        }
        for (auto i: oslot->cardList)
        {
            CardButton* it = dynamic_cast<CardButton*>(i);
            strenth = it->card->currentCombatValue;
            if (max == strenth)
            {
                battleField->move("ocemetery", it);
            }
        }
    }
    emit battleField->finishOneRound();
}
