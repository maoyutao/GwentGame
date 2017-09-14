#include "card_15.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_15::Card_15(BattleField *battleField, QObject *parent):
    Card(15, 6, "Crone: Whispess", "部署：从牌组打出“煮婆”和“织婆”。",
         ":/new/cards/resource/cards/card_15.png",
         EQuality::Silver, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::Waste);
}

void Card_15::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    battleField->move(battleField->mBack, button);
    for (int it: battleField->mDeck)
    {
        if (it == 14 || it == 16)
        {
            battleField->mDeck.removeOne(it);
            CardButton * card = new CardButton(it, battleField, nullptr);
            card->card->first = false;
            card->card->exertAbility();
        }
    }
    if (first)
    {
        battleField->finishOneRound();
    }
}
