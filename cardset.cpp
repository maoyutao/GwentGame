#include "cardset.h"
#include "cards.h"

CardSet::CardSet(QString name, QList<int> allCards): name(name), allCards(allCards)
{
}

CardSet::CardSet(QString name): name(name)
{
}

bool isValidate();

void CardSet::addCard(int id)
{
    if (allCards.isEmpty())
    {
        Card* card = static_cast<Card*>(CardFactory::CreateObject(id, nullptr, nullptr));
        cover = card->iconUrl;
        delete card;
    }
    allCards.append(id);
}

void CardSet::removeCard(int id)
{
    allCards.removeOne(id);
}
