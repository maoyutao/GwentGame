#ifndef W_PLAY_H
#define W_PLAY_H

#include "player.h"
#include "game.h"
#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class MainWindow;
}

class Play : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Play(QWidget *parent = nullptr);
    void init(Player* player, Ui::MainWindow *ui);
signals:

public slots:

private:
    Ui::MainWindow *ui{nullptr};
    Player* player{nullptr};
    Game * game{nullptr};
};

#endif // W_PLAY_H
