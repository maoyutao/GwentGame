#ifndef CARD_10_H
#define CARD_10_H

#include "card.h"
#include <QObject>

class Card_10 : public Card
{
public:
    explicit Card_10(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_10_H
