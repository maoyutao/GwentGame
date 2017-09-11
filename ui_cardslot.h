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

    void addCard(QWidget * widget, int index = -1); // 这里的index是牌的index （经过计算的）
    void addPCard(QWidget * widget, int index); // 这里的index是原始的index （算上左右箭头和strenth）
    void removeCard(QWidget * widget);
    void setLimit(int newLimit);
    void clear();
    int getIndex(QWidget * widget);
    int getPIndex(QWidget *widget);
    void setAllEnabled(bool enabled);
    bool empty{true};
private:
    int limit{10};
    void showButton();
    void addPage();
private slots:
    void createLayout();
    void hideButtonIfNeeded();
};

#endif // UI_CARDSLOT_H
