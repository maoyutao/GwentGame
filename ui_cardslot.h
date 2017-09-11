#ifndef UI_CARDSLOT_H
#define UI_CARDSLOT_H

#include "ui_toprepagebutton.h"
#include "ui_tonextpagebutton.h"
#include <QWidget>
#include <QStackedWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QList>
#include <QPushButton>

class CardSlot : public QStackedWidget
{
    Q_OBJECT
public:
    explicit CardSlot(QWidget *parent = nullptr);

    void addCard(QPushButton * widget, int index = -1); // 这里的index是牌的index （经过计算的）
    void addCard(QList<QPushButton*> widgets);
    void removeCard(QPushButton * widget);
    void setLimit(int newLimit);
    void replaceCard(QPushButton * toBeReplaced, QPushButton* replace);
    void setAllEnabled(bool enabled);
    void clear();
    QList<QPushButton*> allButtons;
private:
    int limit{10};
    void repaint();
private slots:
};

#endif // UI_CARDSLOT_H
