#include "card_8.h"
#include "ui_cardbutton.h"
#include "ui_cardslot.h"
#include "w_battlefield.h"

Card_8::Card_8(BattleField *battleField, QObject *parent):
    Card(8, 6, "Dagon", "佚亡、坚守。部署：生成“刺骨冰霜”、“蔽日浓雾”或“倾盆大雨”。", ":/new/cards/resource/cards/card_8.png",
         EQuality::Gold, EClassification::Leader, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Aquatic);
}

void Card_8::exertAbility()
{
    QList<int> positon;
    positon << SLOTMBACK << SLOTMFRONT << SLOTMMMIDLE;
    choosePosition(positon);
}

void Card_8::afterChoosePosition(CardSlot *slot)
{
     basicAfterChoosePosition();
     battleField->move(slot, button);
     battleField->setAllHandCardExertable(false);
     CardButton* frost = new CardButton(1, battleField, nullptr);
     CardButton* frog = new CardButton(2, battleField, nullptr);
     CardButton* ran = new CardButton(3, battleField, nullptr);
     list.append(frog);
     list.append(frost);
     list.append(ran);
     emit battleField->showToBechosen(list);
     connect(frost, SIGNAL(selected(CardButton* card)), frost->card, SLOT(exertAbility()));
     connect(frog, SIGNAL(selected(CardButton* card)), frog->card, SLOT(exertAbility()));
     connect(ran, SIGNAL(selected(CardButton* card)), ran->card, SLOT(exertAbility()));

}
