#ifndef P_EDIT_H
#define P_EDIT_H

#include "player.h"
#include <QWidget>
#include <QStackedWidget>

class Edit : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Edit(QWidget *parent = nullptr);

    void init(Player * player);

signals:

public slots:

private:
    Player * player{nullptr};
};

#endif // P_EDIT_H
