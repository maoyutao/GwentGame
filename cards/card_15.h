#ifndef CARD_15_H
#define CARD_15_H

#include "card.h"
#include <QObject>

class Card_15 : public Card
{
public:
    explicit Card_15(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
};

#endif // CARD_15_H
