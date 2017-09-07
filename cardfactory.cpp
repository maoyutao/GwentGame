#include "cardfactory.h"

CardFactory::CardFactory()
{

}

void* CardFactory::CreateObject(int cardId, BattleField * BattleField, QObject *parent)
{
    if (cardId < cardList.count())
    {
        newCardFunctionPtr card = cardList[cardId];
        return card(BattleField, parent);
    }
    return nullptr;
}

void CardFactory::RegisterClass(int cardId, newCardFunctionPtr np)
{
    cardList[cardId] = np;
}
