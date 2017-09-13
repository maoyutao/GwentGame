#include "card_5.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"
#include "ui_cardbutton.h"

Card_5::Card_5(BattleField *battleField, QObject *parent):
    Card(5, 0, "Commander's Horn", "使 5 个相邻单位获得 4 点增益。", ":/new/cards/resource/cards/card_5.png",
         EQuality::Silver, EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Strategy);
    property.append(EProperty::Special);
}

void Card_5::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    QList<int> cards;
    int total = battleField->cardsOnBoard.count();
    if (!total)
    {
        battleField->move(nullptr, button);
        emit battleField->finishOneRound();
    }
    for (int i = 0; i < total; i++)
    {
        cards.append(i);
    }
    chooseCardOnBoard(cards);
}

void Card_5::afterChooseCard(CardButton *card)
{
    basicAfterChooseCard();
    QList<QPushButton*> list = card->slot->cardList;
    QList<CardButton*> targets;
    int total = list.count();
    if (total <= 5)
    {
        for (auto it: list)
        {
            targets.append(dynamic_cast<CardButton*>(it));
        }
    } else {
        int theCard = list.indexOf(card);
        int k = theCard - 3;
        while ((k + 5) >= total)
        {
            k--;
        }
        while (k < 0) {
            k++;
        }
        for (int i = k; i < k + 5; i++)
        {
            targets.append(dynamic_cast<CardButton*>(list.at(i)));
        }
    }
    for (auto it: targets)
    {
        battleField->changeStrenth(4, it);
    }
    battleField->move(nullptr, button);
    emit battleField->finishOneRound();
}


