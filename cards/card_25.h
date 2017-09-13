#ifndef CARD_25_H
#define CARD_25_H

#include "card.h"
#include <QObject>

class Card_25 : public Card
{
public:
    explicit Card_25(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
};

#endif // CARD_25_H
