#ifndef CARD_4_H
#define CARD_4_H

#include "card.h"
#include <QObject>

class Card_4 : public Card
{
public:
    explicit Card_4(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_4_H
