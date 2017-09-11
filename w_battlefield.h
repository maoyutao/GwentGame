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
typedef void (BattleField::*standardSlot)(CardButton*);

namespace Ui {
class MainWindow;
}

class BattleField : public QWidget
{
    Q_OBJECT
public:
    explicit BattleField(QWidget *parent = nullptr);

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

    int signalTimes{0};
    int signalTimesLimit{0};
signals:

public slots:
    void init(CardSet* cardset, Ui::MainWindow *aui);

private slots:
    void dispatchCard(CardButton* card);
    void changePageToGaming();

private:
    void shuffle();
    void swapInt(int &a, int &b);
    QList<CardButton*> drawCards(int count = 1);
    void showToBechosen(QList<CardButton*> list, standardSlot slot); // 在choose槽里展示list里的button  并为这些button的selected绑定这个类中的标准槽

    friend class Card;
};

#endif // W_BATTLEFIELD_H
