#include "card_4.h"
#include "ui_cardbutton.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_6::Card_6(BattleField *battleField, QObject *parent):
    Card(6, 0, "Bekker's Twisted Mirror", "对场上最强的单位造成数值等同于其战力的伤害，但最多不超过 10 点（无视护甲），并使场上最弱的非同名单位获得相同数值的增益。",
         ":/new/cards/resource/cards/card_6.png",
         EQuality::Silver, EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Magic);
    property.append(EProperty::Special);
}

void Card_6::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    if (!(battleField->cardsOnBoard.empty()))
    {
        int max = -1;
        int min = -1;
        CardButton* maxbtn;
        CardButton* minbtn;
        int strenth;
        for (CardButton* it: battleField->cardsOnBoard)
        {
            strenth = it->card->currentCombatValue;
            if ((max == -1) || strenth > max)
            {
                max = strenth;
                maxbtn = it;
            }
            if ((min == -1) || strenth < min)
            {
                min = strenth;
                minbtn = it;
            }
        }
        if (max > 10)
        {
            max = 10;
        }
        battleField->changeStrenth(max, minbtn, true, false);
        max = -max;
        battleField->changeStrenth(max, maxbtn);
    }
    battleField->move(nullptr, button);
    emit battleField->finishOneRound();
}

