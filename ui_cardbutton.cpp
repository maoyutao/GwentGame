#include "ui_cardbutton.h"
#include <QStringBuilder>
#include <QSize>
#include <QDebug>
#include <QTimer>

CardButton::CardButton(int cardID, BattleField * battleField, QWidget *parent) : QPushButton(parent),
    card(static_cast<Card*>(CardFactory::CreateObject(cardID, battleField, this)))
{
    if (cardID < 0)
    {
        this->setEnabled(false);
        this->setStyleSheet("border-image: url(:/new/prefix1/resource/o_deck.png)");
        return;
    }
    this->setStyleSheet("border-image: url(" % card->iconUrl % ")");
}

CardButton::~CardButton()
{
//    qDebug() << "delete cardButton" << card->id;
}

void CardButton::setChooseable(bool mchooseable)
{
    if (mchooseable)
    {
        mclickEffect = clickEffect::select;
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
    infoBox->setStyleSheet("border-image: url(" % card->iconUrl % ")");
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(stopShowInfo()), Qt::UniqueConnection);
    connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()), Qt::UniqueConnection);
    timer->start(1200);
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
    if (mclickEffect == clickEffect::select)
    {
        emit selected(this);
    } else if (mclickEffect == clickEffect::showInfo)
    {
        showInfo();
    }
}

void CardButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (exertable)
    {
        card->exertAbility();
    }
}
