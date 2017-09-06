#include "cards.h"

Card::Card(int id,
           int basisCombatValue,
           QString name,
           QString functionDeclaration,
           QPixmap icon,
           QVector<EPosition> position,
           EQuality quality,
           EClassification classification,
           QVector<EProperty> Property,
           BattleField * BattleField,
           QObject *parent
           ):QObject(parent),
            id(id),
            basisCombatValue(basisCombatValue),
            name(name),
            functionDeclaration(functionDeclaration),
            icon(icon),
            position(position),
            quality(quality),
            classification(classification),
            Property(Property),
            currentCombatValue(basisCombatValue),
            mBattleField(BattleField)
{

}

