#include "card_18.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"


Card_18::Card_18(BattleField *battleField, QObject *parent):
    Card(18, 8, "Caranthir", "部署：将 1 个敌军单位移至其所在半场同排，并在此排降下“刺骨冰霜”。",
         ":/new/cards/resource/cards/card_18.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::WildHunt);
}

void Card_18::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    QList<int> pos;
    pos << SLOTMBACK << SLOTMFRONT << SLOTMMMIDLE;
    choosePosition(pos);
}

void Card_18::afterChoosePosition(CardSlot *slot)
{
    mslot = slot;
    QList<int> cards;
    for (auto it: battleField->oBack->cardList)
    {
        cards.append(dynamic_cast<CardButton*>(it)->card->id);
    }
    for (auto it: battleField->oMiddle->cardList)
    {
        cards.append(dynamic_cast<CardButton*>(it)->card->id);
    }
    for (auto it: battleField->oFront->cardList)
    {
        cards.append(dynamic_cast<CardButton*>(it)->card->id);
    }
    chooseCardOnBoard(cards);
}


void Card_18::afterChooseCard(CardButton *card)
{
    int i = battleField->cardSlot.indexOf(mslot);
    battleField->move(battleField->cardSlot[5 - i], card);
    CardButton* frost = new CardButton(1, battleField, nullptr);
    frost->card->first = false;
    battleField->changeSpecialCard(mslot, "add", frost);
    emit battleField->finishOneRound();
}


