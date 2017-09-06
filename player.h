#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

class Player : public QObject
{
    Q_OBJECT
private:
    int point;
    QList<int> allCards;
    QMap<QString, QList<int>> cardSets;
    QList<int> chosenCards;
public:
    explicit Player(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PLAYER_H
