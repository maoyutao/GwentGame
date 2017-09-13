#include "card.h"

Card::Card(int id,
           int basisCombatValue,
           QString name,
           QString functionDeclaration,
           QString iconUrl,
           EQuality quality,
           EClassification classification,
           BattleField * battleField,
           QObject *parent
           ):QObject(parent),
            id(id),
            basisCombatValue(basisCombatValue),
            name(name),
            functionDeclaration(functionDeclaration),
            iconUrl(iconUrl),
            quality(quality),
            classification(classification),
            currentCombatValue(basisCombatValue),
            battleField(battleField)
{

}

void Card::choosePosition(QList<int> chooseableSlot)
{
    for (int i: chooseableSlot)
    {
        CardSlot* slot = battleField->cardSlot[i];
        slot->setChooseable(true);
        connect(slot, SIGNAL(selected(CardSlot*)), this, SLOT(afterChoosePosition(CardSlot)));
    }
}

void Card::afterChoosePosition(CardSlot* slot)
{

}
