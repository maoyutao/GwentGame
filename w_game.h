#ifndef W_GAME_H
#define W_GAME_H

#include "w_game.h"
#include "player.h"
#include "w_battlefield.h"
#include <QWidget>
#include <QStackedWidget>
#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

namespace Ui {
class MainWindow;
}

class Game;

typedef void (Game::*standardSlot)(CardButton*);
typedef QMap<QString, QString> Msg;
typedef void (Game::*msgHandler)(Msg msgMap);

class Game : public QStackedWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    void init(Player* player, Ui::MainWindow *ui);
signals:

public slots:
    void startNewRound();
    void timeout();
    void sendMsg(QMap<QString, QString> msgMap);

private slots:
    void asClient();
    void asServer();
    void onConnect();
    void onNewConnection();
    void chooseCardSet();
    void start(CardSet* cardSet);
    void dispatchCard(CardButton* card);
    void returnToField();
    void clearChooseSlot();
    void changePageToGaming();
    void showToBechosen(QList<CardButton*> list, standardSlot slot = &Game::returnToField); // 在choose槽里展示list里的button  并为这些button的selected绑定这个类中的标准槽 默认是回战场
    void receiveMsg();
private:
    QMap<QString, msgHandler> handlers;
    Ui::MainWindow *ui{nullptr};
    BattleField* battleField;
    Player* player{nullptr};
    QTcpSocket* socket{nullptr};
    QTcpServer* server{nullptr};
    int mScore[3];
    int oScore[3];

    int signalTimes{0};
    int signalTimesLimit{0};

    bool myRound{false};
    bool ready[2]{false, false}; // 0是我 1是对方
    bool on{false};

private:
    Msg parse(QString msg);
    QString stringify(Msg msgMap);
    void msgHandler(Msg msgMap);

    void hReady(Msg msgMap);
    void hStart(Msg msgMap);
    void hChangeRound(Msg msgMap);
    void hChangeStrenth(Msg msgMap);
    void hMove(Msg msgMap);
    void hohandChange(Msg msgMap);
    void hSpecialCard(Msg msgMap);
};

#endif // W_GAME_H
