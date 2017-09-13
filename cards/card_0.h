#ifndef CARD_0_H
#define CARD_0_H

#include "card.h"
#include <QObject>

class Card_0 : public Card
{
public:
    explicit Card_0(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
    void exertAbility() override;
private:
    QList<CardButton*> list;
};

#endif // CARD_0_H
