#include "ui_cardbutton.h"
#include <QStringBuilder>
#include <QSize>
#include <QDebug>

CardButton::CardButton(int cardID, BattleField * battleField, QWidget *parent) : QPushButton(parent),
    card(static_cast<Card*>(CardFactory::CreateObject(cardID, battleField, this)))
{
    this->setStyleSheet("border-image: url(" % card->iconUrl % ")");
}

CardButton::~CardButton()
{
    qDebug() << "delete cardButton" << card->id;
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

void CardButton::mousePressEvent(QMouseEvent *event)
{
    emit seletced(this);
    QPushButton::mousePressEvent(event);
}
