#include "card_17.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"
#include "cardEnum.h"
#include <QList>

Card_17::Card_17(BattleField *battleField, QObject *parent):
    Card(17, 8, "Archgriffin", "部署：移除所在排的天气效果。将 1 张铜色牌从一方墓场置入另一方墓场",
         ":/new/cards/resource/cards/card_17.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Beast);
}

void Card_17::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    QList<int> positon;
    positon << SLOTMBACK << SLOTMFRONT << SLOTMMMIDLE;
    choosePosition(positon);
}

void Card_17::afterChoosePosition(CardSlot *slot)
{
    basicAfterChoosePosition();
    battleField->move(slot, button);
    slot->removeSpecialCard();
    QList<CardButton *> list;
    for (auto it: battleField->mCemetery)
    {
        CardButton* card = new CardButton(it, battleField, nullptr);
        if (card->card->quality == EQuality::Copper)
        {
            list.append(card);
            connect(card, SIGNAL(selected(CardButton*)), this, SLOT(moveToOC(CardButton*)));
        } else {
            card->deleteLater();
        }
    }
    battleField->showToBechosen(list);
}

void Card_17::moveToOC(CardButton *card)
{
    battleField->move("ocemetery", card);
    emit battleField->finishOneRound();
}
