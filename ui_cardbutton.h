#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include "cards.h"
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

enum class clickEffect
{
    showInfo,
    select,
};

class CardButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CardButton(int cardID, BattleField * battleField, QWidget *parent = nullptr);
    ~CardButton();
    Card * card;
    bool exertable{false};
    void setChooseable(bool mchooseable);
    clickEffect mclickEffect{clickEffect::select};
    QWidget* infoBox{nullptr};
signals:
    void selected(CardButton* card);
public slots:
    void stopShowInfo();
private:
    void setInfoBox(QWidget* box);
    void showInfo();
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;

};
#endif // CARDBUTTON_H
