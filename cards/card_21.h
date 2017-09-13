#ifndef CARD_21_H
#define CARD_21_H

#include "card.h"
#include <QObject>

class Card_21 : public Card
{
public:
    explicit Card_21(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_21_H
