#ifndef CARDBUTTON_H
#define CARDBUTTON_H

#include "cards.h"
#include <QWidget>
#include <QPushButton>

class CardButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CardButton(Card * card, QWidget *parent = nullptr);

signals:

public slots:
private:
    Card * card;
};
#endif // CARDBUTTON_H
