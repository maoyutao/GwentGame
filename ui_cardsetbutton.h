#ifndef UI_CARDSETBUTTON_H
#define UI_CARDSETBUTTON_H

#include "cardset.h"
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

class CardSetButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CardSetButton(CardSet* cardSet, QWidget *parent = nullptr);

signals:
    void seletced(CardSet* cardSet);
public slots:
private:
    void paintEvent(QPaintEvent *event) override;
    CardSet* cardSet{nullptr};
    void mousePressEvent(QMouseEvent* event) override;
};

#endif // UI_CARDSETBUTTON_H

