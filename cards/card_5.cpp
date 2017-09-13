#ifndef CARD_5_H
#define CARD_5_H

#include "card.h"
#include <QObject>

class Card_5 : public Card
{
public:
    explicit Card_5(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_5_H
