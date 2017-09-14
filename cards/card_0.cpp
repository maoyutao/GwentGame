#include "card_0.h"
#include "cardfactory.h"
#include "ui_cardbutton.h"

Card_0::Card_0(BattleField *battleField, QObject *parent):
    Card(0, 0, "First Light", "生成“晴空”或“重整”。", ":/new/cards/resource/cards/card_0.png", EQuality::Copper,
         EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Special);
}

void Card_0::exertAbility()
{
    battleField->setAllHandCardExertable(false);
    CardButton* light = new CardButton(24, battleField, nullptr);
    CardButton* re = new CardButton(25, battleField, nullptr);
    list.append(light);
    list.append(re);
    emit battleField->showToBechosen(list);
    connect(light, SIGNAL(selected(CardButton* card)), light->card, SLOT(exertAbility()));
    connect(re, SIGNAL(selected(CardButton* card)), re->card, SLOT(exertAbility()));
    battleField->move("mcemetery", button);
}
