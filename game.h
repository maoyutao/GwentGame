#ifndef GAME_H
#define GAME_H

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

public:
    explicit Game(Player * player, QObject *parent = nullptr);

    int mScore[3];
    int oScore[3];

    Player* mPlayer = nullptr;
    BattleField* battleField = nullptr;

signals:

public slots:
};

#endif // GAME_H
