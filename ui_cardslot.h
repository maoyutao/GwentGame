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

    void addCard(QPushButton * widget);
    void removeCard(QPushButton * widget); // 不会delete
    void removeCard(); // 移除第一张卡
    void setLimit(int newLimit);
    void clear();
    void replaceCard(QPushButton * toBeReplaced, QPushButton * replace); // will delete toBeReplaced
    void setAllEnabled(bool enabled);
    void setChooseable(bool mchooseable);
    void addSpecialCard(CardButton * widget);
    void removeSpecialCard();

    bool empty{true};
    QList<QPushButton *> cardList; // 用pushbutton而不是cardbutton因为这样卡牌集也可以放 以后可能可以放别的 但是外面用的时候注意动态转换类型
    bool chooseable{false};
    CardButton* specialCard;
signals:
    void selected(CardSlot*);
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
