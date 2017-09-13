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

typedef QMap<QString, QString> Msg;

class BattleField : public QWidget
{
    Q_OBJECT
public:
    explicit BattleField(QWidget *parent = nullptr);
    QList<CardButton*> drawCards(int count = 1);
    QList<CardButton*> drawCards(int count, int except);


    void addCardToMDeck(int id);
    void randomlyExertCard();
    void move(CardSlot* to, CardButton * card, bool sendmsg = true);
    void move(QString to, CardButton * card, bool sendmsg = true);
    void changeStrenth(int changeValue, CardButton * target, bool sendmsg = true, bool anmror = true);
    void addCardToOhand();
    void removeCardFromOhand();
    void drawCardTohand();
    void changeSpecialCard(CardSlot* slot, QString way, CardButton * card, bool sendmsg = true);

public:
    CardSet* mCardSet; //参赛的卡组
    Ui::MainWindow *ui{nullptr};
    CardSlot* mFront;
    CardSlot* mMiddle;
    CardSlot* mBack;
    CardSlot* mHand;
    CardButton* mleader{nullptr};
    QList<int> mCemetery;
    QList<int> mDeck;
    CardSlot* oFront;
    CardSlot* oMiddle;
    CardSlot* oBack;
    CardSlot* oHand;
    QMap<CardSlot*, int> strenth;
    int mStrenth{0};
    int oStrenth{0};

    QList<CardSlot*> cardSlot;
    QList<CardButton*> cardsOnBoard; // 双方共享的索引

signals:
    void finishOneRound();
    void sendMsg(QMap<QString, QString> msg);
    void showToBechosen(QList<CardButton*> list);
    void clearChooseSlot();

public slots:
    void initForFirst(Ui::MainWindow *aui);
    void setCardSet(CardSet* cardset);
    void init();
    void setAllHandCardExertable(bool exertable);

private slots:

private:
    void shuffle();
    void swapInt(int &a, int &b);
    void updateStrenthSum();
    void doBeforeARound();
    void addCardToMCemetery(CardButton* card);

    friend class Game;
};

#endif // W_BATTLEFIELD_H
