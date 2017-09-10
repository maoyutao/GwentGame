#include "ui_standardbutton.h"
#include <QFont>

StandardButton::StandardButton(QWidget *parent) : QPushButton(parent)
{
    this->setStyleSheet("border-image: url(:/new/prefix1/resource/button.png)");
    this->setMaximumSize(50, 20);
    QFont font;
    font.setPointSize(12);
    this->setFont(font);
    QPalette palette2;
    QBrush brush7(QColor(197, 197, 197, 191));
    QBrush brush2(QColor(148, 148, 148, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
    palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
    palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    this->setPalette(palette2);
}
