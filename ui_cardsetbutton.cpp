#include "ui_cardsetbutton.h"
#include <QStringBuilder>
#include <QDebug>

CardSetButton::CardSetButton(CardSet* cardSet, QWidget *parent) : QPushButton(parent), cardSet(cardSet)
{
    if (!cardSet)
    {
        this->setStyleSheet("border-image: url(:/new/prefix1/resource/new_cardset.png)");
        return;
    }
    this->setStyleSheet("border-image: url(" % cardSet->cover % ")");
}

void CardSetButton::paintEvent(QPaintEvent *event)
{
    int height = this->parentWidget()->height();
    int width = height * 0.7;
    this->resize(QSize(width, height));
    if (this->pos().ry())
    {
        this->move(QPoint(this->pos().rx(), 0));
    }
    QPushButton::paintEvent(event);
}
