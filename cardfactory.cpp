#include "cardfactory.h"

CardFactory::CardFactory()
{

}

void* CardFactory::CreateObject(int cardId, BattleField * BattleField, QObject *parent)
{
    QMap<int, newCardFunctionPtr>::const_iterator it = cardMap.find(cardId);
    if (it != cardMap.end())
    {
        newCardFunctionPtr card = it.value();
        return card(BattleField, parent);
    }
    return nullptr;
}

void CardFactory::RegisterClass(int cardId, newCardFunctionPtr np)
{
    cardMap[cardId] = np;
}
