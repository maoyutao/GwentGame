#include "ui_cardslot.h"
#include <QHBoxLayout>
#include <QDebug>

CardSlot::CardSlot(QWidget *parent) : QWidget(parent), mlayout(new QHBoxLayout())
{
    qDebug() << this->layout();
    mlayout->setMargin(5);
    mlayout->setSpacing(2);
    this->setLayout(mlayout);
    qDebug() << this->layout();
    qDebug() << this->styleSheet();
}

void CardSlot::paintEvent(QPaintEvent *event)
{
    this->setLayout(mlayout);
    this->setFixedSize(this->parentWidget()->width(), this->parentWidget()->height());
    this->move(QPoint(0,0));
    qDebug() << this->geometry();
    QWidget::paintEvent(event);
}
