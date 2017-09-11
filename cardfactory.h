#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "w_battlefield.h"
#include <QObject>
#include <QMap>

typedef void* (*newCardFunctionPtr)(BattleField * BattleField, QObject *parent);

class CardFactory
{
public:
    CardFactory();
    static void* CreateObject(int cardId, BattleField * BattleField = nullptr, QObject *parent = nullptr);
    static void RegisterClass(int cardId, newCardFunctionPtr np);
//private:
    static QMap<int, newCardFunctionPtr> cardMap;
};

class Register
{
public:
    Register(int cardId, newCardFunctionPtr np)
    {
       CardFactory::RegisterClass(cardId, np);
    }
};
#endif // CARDFACTORY_H
