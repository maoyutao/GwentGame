#ifndef UI_CARDSLOT_H
#define UI_CARDSLOT_H

#include "ui_toprepagebutton.h"
#include "ui_tonextpagebutton.h"
#include "ui_cardbutton.h"
#include <QWidget>
#include <QStackedWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QList>

class CardSlot : public QStackedWidget
{
    Q_OBJECT
public:
    explicit CardSlot(QWidget *parent = nullptr);

    void addCard(QPushButton * widget, int index = -1); // 这里的index是牌的index （经过计算的）
    void addPCard(QPushButton * widget, int index); // 这里的index是原始的index （算上左右箭头和strenth）
    void removeCard(QPushButton * widget);
    void removeCard(); // 移除第一张卡
    void setLimit(int newLimit);
    void clear();
    void replaceCard(QPushButton * toBeReplaced, QPushButton * replace);
    void setAllEnabled(bool enabled);
    void setChooseable(bool mchooseable);
    void addSpecialCard(CardButton * widget);
    void removeSpecialCard(CardButton * widget);
    void clearSpecialCard();

    bool empty{true};
    QList<QPushButton *> cardList; // 用pushbutton而不是cardbutton因为这样卡牌集也可以放 以后可能可以放别的 但是外面用的时候注意动态转换类型
    bool chooseable{false};
    QList<CardButton *> specialCard;
signals:
    void selectd(CardSlot*);
private:
    int limit{7};
    void showButton();
    void addPage();
    void mousePressEvent(QMouseEvent *event);
private slots:
    void createLayout();
    void hideButtonIfNeeded();
};

#endif // UI_CARDSLOT_H
