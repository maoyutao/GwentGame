#include "ui_cardbutton.h"
#include <QStringBuilder>
#include <QSize>
#include <QDebug>

CardButton::CardButton(Card * card, QWidget *parent) : QPushButton(parent), card(card)
{
    this->setStyleSheet("border-image: url(" % card->iconUrl % ")");
}

void CardButton::paintEvent(QPaintEvent *event)
{
    height = this->parentWidget()->height() * 0.9;
    width = height * 0.7;
    this->setFixedHeight(height);
    this->setFixedWidth(width);
    QPushButton::paintEvent(event);
}
