#ifndef CARD_8_H
#define CARD_8_H

#include "card.h"
#include <QObject>

class Card_8 : public Card
{
public:
    explicit Card_8(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_8_H
