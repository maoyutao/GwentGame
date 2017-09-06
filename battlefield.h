#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "global.h"
#include <QObject>
#include <QList>
#include <QMap>

class BattleField : public QObject
{
    Q_OBJECT
private:
    QList<int> mFront;
    QList<int> mMiddle;
    QList<int> mBack;
    QList<int> mHand;
    QList<int> mCemetery;
    QList<int> mDeck;
    QList<int> oFront;
    QList<int> oMiddle;
    QList<int> oBack;
    int oHandNum;
    int oDeckNum;
    QMap<EPosition, int> event;
    // 012 front middle back  3-all
    int mStrenth[4];
    int oStrenth[4];

public:
    explicit BattleField(QObject *parent = nullptr);

signals:

public slots:
    friend class Card;



};

#endif // BATTLEFIELD_H
