#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include "cards/index.h"
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class CardButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CardButton(int cardID, BattleField * battleField, QWidget *parent = nullptr);
    ~CardButton();
    Card * card;
    bool exertable{false};
    QWidget* infoBox{nullptr};
    CardSlot * slot;


    bool selectable{true};
    void setChooseable(bool mchooseable);
    void setInfoBox(QWidget* box);
signals:
    void selected(CardButton* card);
public slots:
    void stopShowInfo();
    void showInfo();
private:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;

};
#endif // CARDBUTTON_H
