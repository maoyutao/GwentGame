#include "ui_tonextpagebutton.h"
#include <QStackedWidget>
#include <QDebug>

ToNextPageButton::ToNextPageButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet("border-image:url(:/new/prefix1/resource/next.png)");
    this->setFixedSize(12,12);
}

void ToNextPageButton::mousePressEvent(QMouseEvent *event)
{
    if (this->parentWidget()->parentWidget()->inherits("QStackedWidget"))
    {
        auto stackedWidget = static_cast<QStackedWidget*>(this->parentWidget()->parentWidget());
        int current = stackedWidget->currentIndex();
        current++;
        if (current >= stackedWidget->count())
        {
            current = 0;
        }
        stackedWidget->setCurrentIndex(current);
    }
    QPushButton::mousePressEvent(event);
}
