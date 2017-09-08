#ifndef UI_CARDSLOT_H
#define UI_CARDSLOT_H

#include <QWidget>
#include <QLayout>

class CardSlot : public QWidget
{
    Q_OBJECT
public:
    explicit CardSlot(QWidget *parent = nullptr);
    QHBoxLayout* mlayout;
signals:

public slots:
private:
//    void paintEvent(QPaintEvent *event) override;
};

#endif // UI_CARDSLOT_H
