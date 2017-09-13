#ifndef CARD_7_H
#define CARD_7_H

#include "card.h"
#include <QObject>

class Card_7 : public Card
{
public:
    explicit Card_7(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_7_H
