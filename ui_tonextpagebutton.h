#ifndef UI_TONEXTPAGEBUTTON_H
#define UI_TONEXTPAGEBUTTON_H

#include <QWidget>
#include <QPushButton>

class ToNextPageButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ToNextPageButton(QWidget *parent = nullptr);

signals:

private:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // UI_TONEXTPAGEBUTTON_H
