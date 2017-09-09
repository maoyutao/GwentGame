#ifndef UI_CARDSLOT_H
#define UI_CARDSLOT_H

#include "ui_toprepagebutton.h"
#include "ui_tonextpagebutton.h"
#include <QWidget>
#include <QStackedWidget>
#include <QLayout>
#include <QHBoxLayout>

class CardSlot : public QStackedWidget
{
    Q_OBJECT
public:
    explicit CardSlot(QWidget *parent = nullptr);
public:
    void addCard(QWidget * widget, int index = -1);
    void removeCard(QWidget * widget);
private:
    void showButton();
    void addPage();
private slots:
    void createLayout();
};

#endif // UI_CARDSLOT_H
