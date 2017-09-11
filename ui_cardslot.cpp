#include "ui_cardslot.h"
#include "ui_cardbutton.h"
#include <QDebug>


CardSlot::CardSlot(QWidget *parent) : QStackedWidget(parent)
{
//    connect(this, SIGNAL(currentChanged(int)), this, SLOT(createLayout()));
//    connect(this, SIGNAL(widgetRemoved(int)), this, SLOT(hideButtonIfNeeded()));
}

//void CardSlot::createLayout()
//{
//    if ((!this->currentWidget()) || this->currentWidget()->layout())
//    {
//        return;
//    }
//    ToNextPageButton* next = new ToNextPageButton(this->currentWidget());
//    ToPrePageButton* pre = new ToPrePageButton(this->currentWidget());
//    QHBoxLayout * mlayout = new QHBoxLayout();
//    mlayout->setMargin(2);
//    mlayout->setSpacing(2);
//    mlayout->addWidget(pre, 0, Qt::AlignLeft);
//    pre->raise();
//    mlayout->addStretch();
//    mlayout->addStretch();
//    mlayout->addWidget(next, 0, Qt::AlignRight);
//    next->raise();
//    if (this->count() == 1)
//    {
//        next->hide();
//        pre->hide();
//    }
//    this->currentWidget()->setLayout(mlayout);
//}

void CardSlot::addCard(QPushButton * widget, int index)
{
    qDebug() << this->allButtons;
    if (index == -1)
    {
        allButtons.append(widget);
        repaint();
        return;
    }
    allButtons.insert(index, widget);
    qDebug() << allButtons;
    repaint();

//    QHBoxLayout * mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());

//    if (index == -1)
//    {
//        if (mlayout->count() >= 4 + limit * 2)
//        {
//            addPage();
//            addCard(widget, index);
//            return;
//        }
//         index = (mlayout->count() - 4) / 2;
//    }
//    mlayout->insertWidget(index * 2 + 2, widget, 0, Qt::AlignCenter);
//    mlayout->insertStretch(index * 2 + 3);
//    widget->raise();

}

void CardSlot::addCard(QList<QPushButton *> widgets)
{
    allButtons.append(widgets);
    repaint();
}

void CardSlot::removeCard(QPushButton *widget)
{
    if (allButtons.removeOne(widget))
    {
        repaint();
    }
//    int count = this->count();
//    QHBoxLayout * mlayout;
//    for (int i = 0; i < count; i++)
//    {
//        mlayout = static_cast<QHBoxLayout*>(this->widget(i)->layout());

//        int windex = mlayout->indexOf(widget);
//        if (windex != -1)
//        {
//            auto strenth = mlayout->itemAt(windex + 1);
//            mlayout->removeItem(strenth);
//            mlayout->removeWidget(widget);
//            break;
//        }
//    }

//    // 如果一页里没有了就删除这页
//    if (mlayout->count() == 4)
//    {
//        if (this->count() <= 1)
//        {
//            return;
//        }
//        QWidget* i = this->currentWidget();
//        int index = this->currentIndex();
//        index--;
//        if (index < 0)
//        {
//            index = this->count() - 1;
//        }
//        this->setCurrentIndex(index);
//        i->deleteLater();
//    }
//    // 整理 todo
}

//void CardSlot::showButton()
//{
//    QHBoxLayout* mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
//    for (int i = 0; i < mlayout->count(); i++)
//    {
//        auto w = mlayout->itemAt(i)->widget() ;
//        if (w && w->inherits("StandardButton"))
//        {
//            w->show();
//        }
//    }
//}

//void CardSlot::addPage()
//{
//    if (this->currentIndex() != -1)
//    {
//        showButton();
//    }
//    QWidget * next = new QWidget();
//    int index = this->addWidget(next);
//    this->setCurrentIndex(index);
//    createLayout();
//}

void CardSlot::repaint()
{
    int current = this->currentIndex();
    QList<QPushButton*> toBeFreed;
    for (auto it: this->children())
    {
        if (it->inherits("QStackedLayout"))
        {
            continue;
        }
        toBeFreed.append(static_cast<QPushButton*>(&*it));
    }
    int total = allButtons.count();
    int count = total / limit + 1;
    for (int k = 0; k < count; k++)
    {
        QWidget* newpage = new QWidget();
        int index = this->addWidget(newpage);
        this->setCurrentIndex(index);
        ToNextPageButton* next = new ToNextPageButton(this->currentWidget());
        ToPrePageButton* pre = new ToPrePageButton(this->currentWidget());
        QHBoxLayout * mlayout = new QHBoxLayout();
        mlayout->setMargin(2);
        mlayout->setSpacing(2);
        mlayout->addWidget(pre, 0, Qt::AlignLeft);
        pre->raise();
        mlayout->addStretch();
        int start =  k * limit;
        int end = (k + 1) * limit;
        for (int i = start; i < end; i++)
        {
            if (i == total)
            {
                break;
            }
            mlayout->addWidget(allButtons.at(i));
            mlayout->addStretch();
            allButtons.at(i)->raise();
        }
        mlayout->addStretch();
        mlayout->addWidget(next, 0, Qt::AlignRight);
        next->raise();
        if (count == 1)
        {
            pre->hide();
            next->hide();
        }
        this->currentWidget()->setLayout(mlayout);
    }
    if (current < count)
    {
        this->setCurrentIndex(current);
    }
    qDeleteAll(toBeFreed);
}

void CardSlot::setLimit(int newLimit)
{
    limit = newLimit;
}

void CardSlot::replaceCard(QPushButton *toBeReplaced, QPushButton *replace)
{
    int index = allButtons.indexOf(toBeReplaced);
    allButtons.replace(index, replace);
    int page = index / limit + 1;
    this->setCurrentIndex(page);
    QHBoxLayout * mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
    int pindex = mlayout->indexOf(toBeReplaced);
    mlayout->insertWidget(pindex, replace);
    toBeReplaced->hide();
    toBeReplaced->deleteLater();
}


void CardSlot::setAllEnabled(bool enabled)
{
    for (auto it: allButtons)
    {
        it->setEnabled(enabled);
    }
}

void CardSlot::clear()
{
    allButtons.clear();
    repaint();
}

//void CardSlot::hideButtonIfNeeded()
//{
//    if (this->count() == 1)
//    {
//        QHBoxLayout* mlayout = static_cast<QHBoxLayout*>(this->currentWidget()->layout());
//        for (int i = 0; i < mlayout->count(); i++)
//        {
//            auto w = mlayout->itemAt(i)->widget() ;
//            if (w && w->inherits("StandardButton"))
//            {
//                w->hide();
//            }
//        }
//    }
//}
