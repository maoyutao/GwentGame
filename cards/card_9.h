#ifndef CARD_9_H
#define CARD_9_H

#include "card.h"
#include <QObject>

class Card_9 : public Card
{
public:
    explicit Card_9(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_9_H
