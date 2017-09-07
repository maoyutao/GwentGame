#ifndef GAME_H
#define GAME_H

#include "global.h"
#include "player.h"
#include "battlefield.h"
#include "cards.h"
#include <QtNetwork>
#include <QHostAddress>
#include <QObject>
#include <QList>

class Game : public QObject
{
    Q_OBJECT
private:
    QHostAddress mAddress;
    QHostAddress oAddress;
    int mPort;
    int oPort;

    int mScore[3];
    int oScore[3];

    Player* mPlayer = nullptr;
    BattleField* battleField = nullptr;
    QList<Card*> mDrawnCard; // 我抽到的牌才需要被实例化，牌组里的不需要
    QList<Card*> oVisibleCard; // 对方只有被打出来的才需要被实例化

public:
    explicit Game(Player * player, QObject *parent = nullptr);

signals:

public slots:
};

#endif // GAME_H
