#ifndef CARD_6_H
#define CARD_6_H

#include "card.h"
#include <QObject>

class Card_6 : public Card
{
public:
    explicit Card_6(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_6_H
