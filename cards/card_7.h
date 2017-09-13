#ifndef CARD_7_H
#define CARD_7_H

#include "card.h"
#include <QObject>

class Card_7 : public Card
{
public:
    explicit Card_7(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private slots:
    void afterChoosePosition(CardSlot * slot) override;
};

#endif // CARD_7_H
