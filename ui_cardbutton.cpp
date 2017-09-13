#include "ui_cardbutton.h"
#include <QStringBuilder>
#include <QSize>
#include <QDebug>
#include <QTimer>

CardButton::CardButton(int cardID, BattleField * battleField, QWidget *parent) : QPushButton(parent)
{
    if (cardID < 0)
    {
        this->setEnabled(false);
        this->setStyleSheet("border-image: url(:/new/prefix1/resource/o_deck.png)");
        return;
    }
    card = static_cast<Card*>(CardFactory::CreateObject(cardID, battleField, this));
    card->button = this;
    this->setStyleSheet("border-image: url(" % card->iconUrl % ")");
}

CardButton::~CardButton()
{
//    qDebug() << "delete cardButton" << card->id;
}

void CardButton::setChooseable(bool chooseable)
{
    if (chooseable)
    {
        this->setStyleSheet("border: 2px solid rgb(131, 219, 255)");
    } else {
        this->setStyleSheet("border: ");
    }
}

void CardButton::stopShowInfo()
{
    if (!infoBox)
    {
        return;
    }
    infoBox->setStyleSheet("border-image: url()");
}

void CardButton::setInfoBox(QWidget *box)
{
    infoBox = box;
}

void CardButton::showInfo()
{
    if (!infoBox)
    {
        return;
    }
    qDebug() << "show " << card->iconUrl;
    infoBox->setStyleSheet("border-image: url(" % card->iconUrl % ")");
    QTimer *time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(stopShowInfo()));
    connect(time, SIGNAL(timeout()), time, SLOT(deleteLater()));
    time->start(1200);
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
    emit selected(this);
    showInfo();
}

void CardButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (exertable)
    {
        card->exertAbility();
    }
}
