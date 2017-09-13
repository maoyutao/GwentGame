#ifndef CARD_11_H
#define CARD_11_H

#include "card.h"
#include <QObject>

class Card_11 : public Card
{
public:
    explicit Card_11(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
};

#endif // CARD_11_H
