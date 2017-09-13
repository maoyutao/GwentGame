#ifndef CARD_24_H
#define CARD_24_H

#include "card.h"
#include <QObject>

class Card_24 : public Card
{
public:
    explicit Card_24(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private:
    bool first = true;
};

#endif // CARD_24_H
