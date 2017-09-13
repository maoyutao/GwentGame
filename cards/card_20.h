#ifndef CARD_20_H
#define CARD_20_H

#include "card.h"
#include <QObject>

class Card_20 : public Card
{
public:
    explicit Card_20(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
};

#endif // CARD_20_H
