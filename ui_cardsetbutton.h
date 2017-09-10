#ifndef UI_CARDSETBUTTON_H
#define UI_CARDSETBUTTON_H

#include "cardset.h"
#include <QWidget>
#include <QPushButton>

class CardSetButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CardSetButton(CardSet* cardSet, QWidget *parent = nullptr);

signals:

public slots:
private:
    void paintEvent(QPaintEvent *event) override;
    CardSet* cardSet{nullptr};
};

#endif // UI_CARDSETBUTTON_H
