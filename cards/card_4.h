#ifndef CARD_4_H
#define CARD_4_H

#include "card.h"
#include <QObject>

class Card_4 : public Card
{
public:
    explicit Card_4(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private slots:
    void afterChoosePosition(CardSlot * slot) override;
};

#endif // CARD_4_H
