#ifndef UI_TOPREPAGEBUTTON_H
#define UI_TOPREPAGEBUTTON_H

#include <QWidget>
#include <QPushButton>

class ToPrePageButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ToPrePageButton(QWidget *parent = nullptr);

private:
    void mousePressEvent(QMouseEvent *event) override;
public slots:
};

#endif // UI_TOPREPAGEBUTTON_H
