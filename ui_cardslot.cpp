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
    if (index == -1)
    {
        if (mlayout->count() >= 4 + limit * 2)
        {
            addPage();
            addCard(widget, index);
            return;
        }
         index = (mlayout->count() - 4) / 2;
    }
    mlayout->insertWidget(index * 2 + 2, widget, 0, Qt::AlignCenter);
    mlayout->insertStretch(index * 2 + 3);
    cardList.append(dynamic_cast<QPushButton*>(widget));

//    for (int i = 0; i < mlayout->count(); i++)
//    {
//        qDebug() << mlayout->itemAt(i)->widget();
//    }

}

void CardSlot::removeCard()
{
    if (cardList.isEmpty())
    {
        return;
    }
    cardList.removeFirst();
    QHBoxLayout* mlayout = static_cast<QHBoxLayout*>(this->widget(0)->layout());
    auto firstcard = mlayout->itemAt(2);
    auto strenth = mlayout->itemAt(3);
    firstcard->deleteLater();
    strenth->deleteLater();
}

void CardSlot::removeCard(QWidget *widget)
{
    cardList.removeOne(dynamic_cast<QPushButton*>(widget));
    int count = this->count();
    QHBoxLayout * mlayout;
    for (int i = 0; i < count; i++)
    {
        mlayout = static_cast<QHBoxLayout*>(this->widget(i)->layout());
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

void CardSlot::mousePressEvent(QMouseEvent *event)
{
    if (chooseable)
    {
        emit selectd(this);
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
}

void CardSlot::replaceCard(QWidget *toBeReplaced, QWidget *replace)
{
    QHBoxLayout * mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
    int index = mlayout->indexOf(toBeReplaced);
    mlayout->insertWidget(index, replace, 0, Qt::AlignCenter);
    toBeReplaced->deleteLater();
    cardList.append(dynamic_cast<QPushButton*>(replace));
    cardList.removeOne(dynamic_cast<QPushButton*>(toBeReplaced));
}

void CardSlot::setAllEnabled(bool enabled)
{
    for (auto it: cardList)
    {
        dynamic_cast<QWidget*>(&*it)->setEnabled(enabled);
    }
//    int count = this->count();
//    QHBoxLayout * mlayout;
//    for (int i = 0; i < count; i++)
//    {
//        mlayout = static_cast<QHBoxLayout*>(this->widget(i)->layout());
//        int layoutcount = mlayout->count();
//        for (int k = 0; k < layoutcount; k++)
//        {
//            auto w = mlayout->itemAt(k)->widget();
//            if (w && w->inherits("QPushButton") && !(w->inherits("ToPrePageButton")) && !(w->inherits("ToNextPageButton")))
//            {
//                w->setEnabled(enabled);
//            }
//        }
    //    }
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

void CardSlot::hideButtonIfNeeded()
{
    if (this->count() == 1)
    {
        this->currentWidget()->layout()->itemAt(0)->widget()->hide();
        int count = this->currentWidget()->layout()->count();
        this->currentWidget()->layout()->itemAt(count - 1)->widget()->hide();
    }
}
