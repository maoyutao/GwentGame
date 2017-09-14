#ifndef CARD_1_H
#define CARD_1_H

#include "card.h"
#include <QObject>

class Card_1 : public Card
{
public:
    explicit Card_1(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private:
    int flag = 0;
    CardSlot* mslot;
private slots:
    void afterChoosePosition(CardSlot * slot) override;
};

#endif // CARD_1_H
