#ifndef CARD_13_H
#define CARD_13_H

#include "card.h"
#include <QObject>

class Card_13 : public Card
{
public:
    explicit Card_13(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_13_H
