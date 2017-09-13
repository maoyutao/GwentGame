#ifndef CARD_8_H
#define CARD_8_H

#include "card.h"
#include <QObject>

class Card_8 : public Card
{
public:
    explicit Card_8(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private:
    QList<CardButton*> list;
private slots:
    void afterChoosePosition(CardSlot * slot) override;
};

#endif // CARD_8_H
