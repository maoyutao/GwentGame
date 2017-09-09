#include "ui_toprepagebutton.h"
#include <QDebug>
#include <QStackedWidget>

ToPrePageButton::ToPrePageButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet("border-image:url(:/new/prefix1/resource/preview.png)");
    this->setFixedSize(12,12);
}

void ToPrePageButton::mousePressEvent(QMouseEvent *event)
{
    if (this->parentWidget()->parentWidget()->inherits("QStackedWidget"))
    {
        auto stackedWidget = static_cast<QStackedWidget*>(this->parentWidget()->parentWidget());
        int current = stackedWidget->currentIndex();
        current--;
        if (current < 0)
        {
            current = stackedWidget->count() - 1;
        }
        stackedWidget->setCurrentIndex(current);
    }
    QPushButton::mousePressEvent(event);
}
