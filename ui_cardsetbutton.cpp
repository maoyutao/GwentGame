#include "ui_cardsetbutton.h"
#include <QStringBuilder>
#include <QDebug>

CardSetButton::CardSetButton(CardSet* cardSet, QWidget *parent) : QPushButton(parent), cardSet(cardSet)
{
    this->setObjectName("cardSetButton" % QString::number(unique++));
    if (!cardSet)
    {
        this->setStyleSheet(borderimage(":/new/prefix1/resource/new_cardset.png"));
        return;
    }
    this->setStyleSheet(borderimage(cardSet->cover));
    this->setToolTip(cardSet->info);
}

CardSetButton::~CardSetButton()
{
    qDebug() << "delete CardSetButton";
}

QString CardSetButton::borderimage(QString url)
{
    return "#" % this->objectName() % " {border-image: url(" % url %")}"
            % "#" % this->objectName() % " *" % " {border-image: url()}";
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

void CardSetButton::mousePressEvent(QMouseEvent *event)
{
    emit seletced(cardSet);
}
