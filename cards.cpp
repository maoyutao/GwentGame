#include "cards.h"

Card::Card(int id,
           int basisCombatValue,
           QString name,
           QString functionDeclaration,
           QString iconUrl,
           QVector<EPosition>* position,
           EQuality quality,
           EClassification classification,
           QVector<EProperty>* Property,
           BattleField * battleField,
           QObject *parent
           ):QObject(parent),
            id(id),
            basisCombatValue(basisCombatValue),
            name(name),
            functionDeclaration(functionDeclaration),
            iconUrl(iconUrl),
            position(position),
            quality(quality),
            classification(classification),
            Property(Property),
            currentCombatValue(basisCombatValue),
            battleField(battleField)
{

}

Card_0::Card_0(BattleField *battleField, QObject *parent):
    Card(0, 0, "First Light", "生成“晴空”或“重整”。", ":/new/cards/resource/card_0.png", new QVector<EPosition>(1, EPosition::Null), EQuality::Copper,
         EClassification::Event, new QVector<EProperty>(1, EProperty::Special), battleField, parent)
{

}
