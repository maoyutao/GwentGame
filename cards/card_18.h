#ifndef CARD_18_H
#define CARD_18_H

#include "card.h"
#include <QObject>

class Card_18 : public Card
{
public:
    explicit Card_18(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private slots:
    void afterChooseCard(CardButton * card) override;
    void afterChoosePosition(CardSlot * slot) override;
    CardSlot* mslot{nullptr};
};

#endif // CARD_18_H
