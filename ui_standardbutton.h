#ifndef STANDARDBUTTON_H
#define STANDARDBUTTON_H

#include <QWidget>
#include <QPushButton>

class StandardButton : public QPushButton
{
    Q_OBJECT
public:
    explicit StandardButton(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // STANDARDBUTTON_H
