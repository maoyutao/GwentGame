#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include "cards.h"
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

signals:
    void seletced(CardButton* card);
public slots:
private:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent* event) override;
};
#endif // CARDBUTTON_H
