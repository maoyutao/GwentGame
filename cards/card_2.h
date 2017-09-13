#ifndef CARD_2_H
#define CARD_2_H

#include "card.h"
#include <QObject>

class Card_2 : public Card
{
public:
    explicit Card_2(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
};

#endif // CARD_2_H


