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
    void selected(CardSet* cardSet);
private slots:
private:
    void paintEvent(QPaintEvent *event) override;
    CardSet* cardSet{nullptr};
    void mousePressEvent(QMouseEvent* event) override;
    QString borderimage(QString url);
    static int unique;
};

#endif // UI_CARDSETBUTTON_H

