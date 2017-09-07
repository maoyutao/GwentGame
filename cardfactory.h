#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "global.h"
#include "battlefield.h"
#include <QObject>
#include <QList>

typedef void* (*newCardFunctionPtr)(BattleField * BattleField, QObject *parent);

class CardFactory
{
public:
    CardFactory();
    static void* CreateObject(int cardId, BattleField * BattleField = nullptr, QObject *parent = nullptr);
    static void RegisterClass(int cardId, newCardFunctionPtr np);
private:
    static QList<newCardFunctionPtr> cardList;
};

QList<newCardFunctionPtr> CardFactory::cardList;

#endif // CARDFACTORY_H
