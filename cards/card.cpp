#include "card.h"
#include "w_battlefield.h"

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

void Card::dyingWish()
{
    button->deleteLater();
}

void Card::choosePosition(QList<int> chooseableSlot)
{
    mChooseableSlot = chooseableSlot;
    for (int i: chooseableSlot)
    {
        CardSlot* slot = battleField->cardSlot[i];
        slot->setChooseable(true);
        connect(slot, SIGNAL(selected(CardSlot*)), this, SLOT(afterChoosePosition(CardSlot*)));
    }
}

void Card::chooseCardOnBoard(QList<int> chooseableCard)
{
    mChooseableCard = chooseableCard;
    for (int i: chooseableCard)
    {
        CardButton* card = battleField->cardsOnBoard[i];
        card->setChooseable(true);
        connect(card, SIGNAL(selected(CardSlot*)), this, SLOT(afterChooseCard()));
    }
}

void Card::afterChoosePosition(CardSlot* slot)
{
    basicAfterChoosePosition();
}

void Card::basicAfterChoosePosition()
{
    for (int i: mChooseableSlot)
    {
        CardSlot* slott = battleField->cardSlot[i];
        slott->setChooseable(false);
        disconnect(slott, SIGNAL(selected(CardSlot*)), this, SLOT(afterChoosePosition(CardSlot*)));
    }
}

void Card::afterChooseCard(CardButton *slot)
{
    basicAfterChooseCard();
}

void Card::basicAfterChooseCard()
{
    for (int i: mChooseableCard)
    {
        CardButton* card = battleField->cardsOnBoard[i];
        card->setChooseable(false);
        disconnect(card, SIGNAL(selected(CardSlot*)), this, SLOT(afterChooseCard()));
    }
}
