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
    int height = this->parentWidget()->height();
    int width = height * 0.7;
    this->resize(QSize(width, height));
    if (this->pos().ry()){
        this->move(QPoint(this->pos().rx(), 0));
    }
    QPushButton::paintEvent(event);
}
