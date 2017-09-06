#ifndef GAME_H
#define GAME_H

#include "global.h"
#include "player.h"
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

    Player* mPlayer;
    BattleField* battleField;
    QList<Card*> mAllCard;
    QList<Card*> oVisibleCard;

public:
    explicit Game(QObject *parent = nullptr);

signals:

public slots:
};

#endif // GAME_H
