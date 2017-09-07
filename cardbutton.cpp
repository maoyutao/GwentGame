#include "cardbutton.h"
#include <QStringBuilder>

CardButton::CardButton(Card * card, QWidget *parent) : QPushButton(parent), card(card)
{
    this->setStyleSheet("border-image: url(" % card->iconUrl % ")");
}
