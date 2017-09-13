#ifndef CARD_14_H
#define CARD_14_H

#include "card.h"
#include <QObject>

class Card_14 : public Card
{
public:
    explicit Card_14(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_14_H
