#ifndef CARD_16_H
#define CARD_16_H

#include "card.h"
#include <QObject>

class Card_16 : public Card
{
public:
    explicit Card_16(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_16_H
