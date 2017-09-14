#ifndef CARD_17_H
#define CARD_17_H

#include "card.h"
#include <QObject>

class Card_17 : public Card
{
public:
    explicit Card_17(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;

private slots:
    void afterChoosePosition(CardSlot * slot) override;
    void moveToOC(CardButton* card);
};

#endif // CARD_17_H
