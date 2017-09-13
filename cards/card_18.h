#ifndef CARD_18_H
#define CARD_18_H

#include "card.h"
#include <QObject>

class Card_18 : public Card
{
public:
    explicit Card_18(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
};

#endif // CARD_18_H
