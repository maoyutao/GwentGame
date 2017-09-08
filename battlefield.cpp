#include "battlefield.h"
#include "cards.h"

BattleField::BattleField(QList<int> mCardSet, QObject *parent) : QObject(parent), mCardSet(mCardSet)
{

}
