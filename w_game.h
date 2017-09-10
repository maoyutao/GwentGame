#ifndef W_GAME_H
#define W_GAME_H

#include "w_game.h"
#include "player.h"
#include "battlefield.h"
#include <QWidget>
#include <QStackedWidget>
#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class Game : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    void init(Player* player, Ui::MainWindow *ui);
signals:

public slots:
private slots:
    void asClient();
    void asServer();
    void onConnect();
    void onNewConnection();
    void chooseCardSet();
    void dispatchCard();
    void start(CardSet* cardSet);
private:
    Ui::MainWindow *ui{nullptr};
    Player* player{nullptr};
    QTcpSocket* socket{nullptr};
    QTcpServer* server{nullptr};
    int mScore[3];
    int oScore[3];
    BattleField* battleField = nullptr;
    QList<Card*> cardList;

};

#endif // W_GAME_H
