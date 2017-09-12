#ifndef W_BATTLEFIELD_H
#define W_BATTLEFIELD_H

#include "cardEnum.h"
#include "ui_cardslot.h"
#include <QWidget>
#include <QList>
#include <QMap>


class BattleField;
class CardButton;
class CardSet;

namespace Ui {
class MainWindow;
}

class BattleField : public QWidget
{
    Q_OBJECT
public:
    explicit BattleField(QWidget *parent = nullptr);
    QList<CardButton*> drawCards(int count = 1);

    void addCardToMDeck(int id);

private:
    CardSet* mCardSet; //参赛的卡组
    Ui::MainWindow *ui{nullptr};
    QList<CardButton*> mFront;
    QList<CardButton*> mMiddle;
    QList<CardButton*> mBack;
    QList<CardButton*> mHand;
    CardButton* mleader{nullptr};
    QList<int> mCemetery;
    QList<int> mDeck;
    QList<CardButton*> oFront;
    QList<CardButton*> oMiddle;
    QList<CardButton*> oBack;

    int oHandNum{0};
    int oDeckNum{0};
    QMap<EPosition, int> event;
    // 012 front middle back  3-all
    int mStrenth[4];
    int oStrenth[4];

    QList<CardButton*> allCards; // 这里卡牌的索引就是本场游戏中卡的索引 起到编号和保存卡的实例的作用 卡牌具体位置信息在上面的list里保存

signals:

public slots:
    void initForFirst(CardSet* cardset, Ui::MainWindow *aui);
    void init();

private slots:

private:
    void shuffle();
    void swapInt(int &a, int &b);

    friend class Card;
};

#endif // W_BATTLEFIELD_H
