#ifndef W_PLAY_H
#define W_PLAY_H

#include "player.h"
#include "game.h"
#include <QWidget>
#include <QStackedWidget>

class Play : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Play(QWidget *parent = nullptr);
    void init(Player* Player);
signals:

public slots:

private:
    Player* Player{nullptr};
    Game * Game{nullptr};
};

#endif // W_PLAY_H
