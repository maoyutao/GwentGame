#ifndef CARD_22_H
#define CARD_22_H

#include "card.h"
#include <QObject>

class Card_22 : public Card
{
public:
    explicit Card_22(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_22_H
