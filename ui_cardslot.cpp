#include "ui_cardslot.h"
#include <QHBoxLayout>
#include <QDebug>

CardSlot::CardSlot(QWidget *parent) : QWidget(parent), mlayout(new QHBoxLayout())
{
    qDebug() << this->layout();
    mlayout->setMargin(2);
    mlayout->setSpacing(2);
    mlayout->addSpacing(20);
    this->setLayout(mlayout);
    qDebug() << this->layout();
}

//void CardSlot::paintEvent(QPaintEvent *event)
//{
//    this->setLayout(mlayout);
//    this->resize(QSize(this->parentWidget()->width(), this->parentWidget()->height()));
//    this->move(QPoint(0,0));
//    qDebug() << this->geometry();
//    QWidget::paintEvent(event);
//}
