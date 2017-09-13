#ifndef CARD_19_H
#define CARD_19_H

#include "card.h"
#include <QObject>

class Card_19 : public Card
{
public:
    explicit Card_19(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

#endif // CARD_19_H
