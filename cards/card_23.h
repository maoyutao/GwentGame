#ifndef CARD_23_H
#define CARD_23_H

#include "card.h"
#include <QObject>

class Card_23 : public Card
{
public:
    explicit Card_23(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_23_H
