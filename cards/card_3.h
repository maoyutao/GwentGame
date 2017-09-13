#ifndef CARD_3_H
#define CARD_3_H

#include "card.h"
#include <QObject>

class Card_3 : public Card
{
public:
    explicit Card_3(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private:
    bool first{true};
    CardSlot* mslot;
private slots:
    void afterChoosePosition(CardSlot * slot) override;
};

#endif // CARD_3_H
