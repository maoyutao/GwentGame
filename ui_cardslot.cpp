#include "ui_cardslot.h"
#include "ui_cardbutton.h"
#include <QDebug>

CardSlot::CardSlot(QWidget *parent) : QStackedWidget(parent)
{
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(createLayout()));
    connect(this, SIGNAL(widgetRemoved(int)), this, SLOT(hideButtonIfNeeded()));
}

void CardSlot::createLayout()
{
    if (this->currentWidget()->layout())
    {
        return;
    }
    ToNextPageButton* next = new ToNextPageButton(this->currentWidget());
    ToPrePageButton* pre = new ToPrePageButton(this->currentWidget());
    QHBoxLayout * mlayout = new QHBoxLayout();
    mlayout->addWidget(pre, 0, Qt::AlignLeft);
    mlayout->addWidget(next, 0, Qt::AlignRight);
    if (this->count() == 1)
    {
        next->hide();
        pre->hide();
    }
    this->currentWidget()->setLayout(mlayout);
}

void CardSlot::addCard(QPushButton * widget)
{
    if (widget->inherits("CardButton"))
    {
        dynamic_cast<CardButton*>(widget)->slot = this;
    }
    QHBoxLayout * mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
    if (mlayout->count() >= 2 + limit)
    {
        addPage();
        addCard(widget);
        return;
    }
    QWidget* next = mlayout->itemAt(mlayout->count() - 1)->widget();
    mlayout->removeWidget(next);
    mlayout->addWidget(widget);
    mlayout->addWidget(next);
    cardList.append(widget);
}

void CardSlot::removeCard()
{
    // remove and delete
    if (cardList.isEmpty())
    {
        return;
    }
    cardList.removeFirst();
    QHBoxLayout* mlayout = static_cast<QHBoxLayout*>(this->widget(0)->layout());
    auto firstcard = mlayout->itemAt(2)->widget();
    mlayout->removeWidget(firstcard);
    firstcard->deleteLater();
}

void CardSlot::removeCard(QPushButton *widget)
{
    if (widget->inherits("CardButton"))
    {
        dynamic_cast<CardButton*>(widget)->slot = nullptr;
    }
    cardList.removeOne(widget);
    int count = this->count();
    QHBoxLayout * mlayout;
    for (int i = 0; i < count; i++)
    {
        mlayout = static_cast<QHBoxLayout*>(this->widget(i)->layout());
        int windex = mlayout->indexOf(widget);
        if (windex != -1)
        {
            mlayout->removeWidget(widget);
            break;
        }
    }
    // 如果一页里没有了就删除这页
    if (mlayout->count() == 2)
    {
        if (this->count() <= 1)
        {
            return;
        }
        QWidget* i = this->currentWidget();
        int index = this->currentIndex();
        index--;
        if (index < 0)
        {
            index = this->count() - 1;
        }
        this->setCurrentIndex(index);
        i->deleteLater();
    }
}

void CardSlot::showButton()
{
    this->currentWidget()->layout()->itemAt(0)->widget()->show();
    int count = this->currentWidget()->layout()->count();
    this->currentWidget()->layout()->itemAt(count - 1)->widget()->show();
}

void CardSlot::addPage()
{
    if (this->currentIndex() != -1)
    {
        showButton();
    }
    QWidget * next = new QWidget();
    int index = this->addWidget(next);
    this->setCurrentIndex(index);
    createLayout();
}

void CardSlot::mousePressEvent(QMouseEvent *event)
{
    if (chooseable)
    {
        emit selected(this);
    }
}

void CardSlot::setLimit(int newLimit)
{
    limit = newLimit;
}

void CardSlot::clear()
{
    for (auto it: this->children())
    {
        if (it->inherits("QStackedLayout"))
        {
            continue;
        }
        it->deleteLater();
    }
    addPage();
    cardList.clear();
    specialCard->deleteLater();
    specialCard = nullptr;
}

void CardSlot::replaceCard(QPushButton *toBeReplaced, QPushButton *replace)
{
    QHBoxLayout * mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
    int index = mlayout->indexOf(toBeReplaced);
    mlayout->insertWidget(index, replace, 0, Qt::AlignCenter);
    if (replace->inherits("CardButton"))
    {
        dynamic_cast<CardButton*>(replace)->slot = this;
    }
    toBeReplaced->deleteLater();
    cardList.append(replace);
    cardList.removeOne(toBeReplaced);
}

void CardSlot::setAllEnabled(bool enabled)
{
    for (auto it: cardList)
    {
        dynamic_cast<QWidget*>(&*it)->setEnabled(enabled);
    }
}

void CardSlot::setChooseable(bool mchooseable)
{
    chooseable = mchooseable;
    if (chooseable)
    {
        this->setStyleSheet("border: 2px solid rgb(131, 219, 255)");
    } else {
        this->setStyleSheet("border: ");
    }
}

void CardSlot::addSpecialCard(CardButton *widget)
{
    if (specialCard)
    {
        delete specialCard;
    }
    specialCard = widget;
    widget->setParent(this);
    widget->setGeometry(0, 0, 10, 10);
    widget->show();
    widget->raise();
}

void CardSlot::removeSpecialCard()
{
    specialCard->deleteLater();
}

void CardSlot::hideButtonIfNeeded()
{
    if (this->count() == 1)
    {
        this->currentWidget()->layout()->itemAt(0)->widget()->hide();
        int count = this->currentWidget()->layout()->count();
        this->currentWidget()->layout()->itemAt(count - 1)->widget()->hide();
    }
}
