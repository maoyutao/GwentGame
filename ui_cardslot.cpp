#include "ui_cardslot.h"
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
    mlayout->setMargin(2);
    mlayout->setSpacing(2);
    mlayout->addWidget(pre, 0, Qt::AlignLeft);
    mlayout->addStretch();
    mlayout->addStretch();
    mlayout->addWidget(next, 0, Qt::AlignRight);
    if (this->count() == 1)
    {
        next->hide();
        pre->hide();
    }
    this->currentWidget()->setLayout(mlayout);
}

void CardSlot::addCard(QWidget * widget, int index)
{
    QHBoxLayout * mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
    if (mlayout->count() > 4 + limit * 2)
    {
        addPage();
        addCard(widget, index);
        return;
    }
    if (index == -1)
    {
         index = mlayout->count() - 4;
    }
    mlayout->insertWidget(index + 2, widget, 0, Qt::AlignCenter);
    mlayout->insertStretch(index + 3);
}

void CardSlot::removeCard(QWidget *widget)
{
    int count = this->count();
    QHBoxLayout * mlayout;
    for (int i = 0; i < count; i++)
    {
        this->setCurrentIndex(i);
        mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
        int windex = mlayout->indexOf(widget);
        if (windex != -1)
        {
            auto strenth = mlayout->itemAt(windex + 1);
            mlayout->removeItem(strenth);
            mlayout->removeWidget(widget);
            break;
        }
    }
    // 如果一页里没有了就删除这页
    if (mlayout->count() == 4)
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
    // 整理 todo
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
