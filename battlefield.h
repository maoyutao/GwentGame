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
    QList<int> mCardSet; // 这里卡牌的索引就是本场游戏中卡的索引？？
    QList<int> mFront;
    QList<int> mMiddle;
    QList<int> mBack;
    QList<int> mHand;
    QList<int> mCemetery;
    QList<int> mDeck;
    QList<int> oFront;
    QList<int> oMiddle;
    QList<int> oBack;
    int oHandNum{0};
    int oDeckNum{0};
    QMap<EPosition, int> event;
    // 012 front middle back  3-all
    int mStrenth[4];
    int oStrenth[4];

//    move(QString from, int cardIndex, QString to);
public:
    explicit BattleField(QList<int> allCards, QObject *parent = nullptr);

signals:

public slots:
    friend class Card;

};

#endif // BATTLEFIELD_H
