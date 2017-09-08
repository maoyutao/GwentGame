#include "ui_standardbutton.h"
#include <QFont>

StandardButton::StandardButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet("border-image: url(:/new/prefix1/resource/button.png)");
    this->setMaximumSize(50, 20);
    QFont font;
    font.setPointSize(12);
    this->setFont(font);
}
