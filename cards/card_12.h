#ifndef CARD_12_H
#define CARD_12_H

#include "card.h"
#include <QObject>

class Card_12 : public Card
{
public:
    explicit Card_12(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
};

#endif // CARD_12_H
