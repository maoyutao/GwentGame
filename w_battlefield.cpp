#include "w_battlefield.h"
#include "cards.h"
#include "cardset.h"
#include "ui_cardbutton.h"
#include "ui_mainwindow.h"
#include "messagedefine.h"
#include <QTimer>
#include <QtGlobal>

#define PGAMEREADY 0
#define PWAITING 1
#define PCHOOSE 2
#define PGAMING 3
#define PSCORE 4
#define PFINALSCORE 5

BattleField::BattleField(QWidget *parent) : QWidget(parent)
{
}

void BattleField::initForFirst(CardSet *cardset, Ui::MainWindow *aui)
{
    mCardSet = cardset;
    ui = aui;
    mFront = ui->gamingMFront;
    mMiddle = ui->gamingMMiddle;
    mBack = ui->gamingMBcak;
    oFront = ui->gamingOFront;
    oMiddle = ui->gamingOMiddle;
    oBack = ui->gamingOBack;
    mHand = ui->mHandSlot;
    oHand = ui->oHandSlot;
    mleader = new CardButton(mCardSet->leader, this, ui->gamingMLeader);
    mDeck = mCardSet->allCards;
    mDeck.removeOne(mCardSet->leader);
    shuffle();
}

void BattleField::init()
{
    // init my hand slot
    for (auto it: ui->gamingChooseSlot->cardList)
    {
        mHand->addCard(&*it);
        CardButton* p = dynamic_cast<CardButton*>(&*it);
        p->mclickEffect = clickEffect::showInfo;
        p->exertable = false;
    }
    mHand->setCurrentIndex(0);

    // init opponent's hand slot
    for (int i = 0; i < 10; i++)
    {
        oHand->addCard(new CardButton(-1, nullptr, oHand));
    }
    oHand->setCurrentIndex(0);

    // init leader
    CardButton* oleader = new CardButton(-1, nullptr, ui->gamingOLeader);
    oleader->raise();
    mleader->show();

    // init strenth
    strenth[mBack] = 0;
    strenth[mFront] = 0;
    strenth[mMiddle] = 0;
    strenth[oBack] = 0;
    strenth[oMiddle] = 0;
    strenth[oFront] = 0;
}
void BattleField::randomlyExertCard()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int index = qrand() % mHand.count();
    mHand.at(index)->card->exertAbility();
}

void BattleField::shuffle()
{
    int n = mDeck.count();
    for(int i=n-1; i>=1; i--)
    {
        swapInt(mDeck[i], mDeck[rand()%(i+1)]);
    }
}

void BattleField::swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BattleField::move(CardSlot *from, CardSlot *to, CardButton *card, bool sendmsg)
{
//    if (from == oHand)
//    {
//        oHand->removeCard();
//        new
//    注册索引
//    } //这块在处理那里写 注意转换一下敌我
    if (from != oHand)
    {
        from->removeCard(card);
    }
    to->addCard(card);
    int mstrenth = card->card->currentCombatValue;
    if (strenth.contains(from))
    {
        strenth[from] -= mstrenth;
    }
    if (strenth.contains(to))
    {
        strenth[to] += mstrenth;
    }
    updateStrenthSum();

    // 注册索引
    if (from == mHand)
    {
        card->card->index = cardsOnBoard.count();
        cardsOnBoard.append(card);
    }
    if (sendmsg)
    {
        QMap<QString, QString> msg;
        msg["type"] = QString::number(MMOVE);
        msg["from"] = from->objectName();
        msg["fromAs"] = "CardSlot";
        msg["to"] = to->objectName();
        msg["toAs"] = "CardSlot";
        msg["card"] = card->card->index;
        emit sendMsg(msg);
    }
}

void BattleField::move(CardSlot *from, QString to, CardButton *card, bool sendmsg)
{
    from->removeCard(card);
    int strenth = card->card->currentCombatValue;
    if (strenth.contains(from))
    {
        strenth[from] -= mstrenth;
    }
    card->deleteLater();
    if (to == "deck")
    {
        mDeck.append(card->card->id);
    }
    if (to == "cemetery")
    {
        mCemetery.append(card->card->id);
    }
    updateStrenthSum();
    if (sendmsg)
    {
        msg["type"] = QString::number(MMOVE);
        msg["from"] = from->objectName();
        msg["fromAs"] = "CardSlot";
        msg["to"] = to;
        msg["toAs"] = "QString";
        msg["card"] = card->card->index;
        emit sendMsg(msg);
    }
}

void BattleField::changeStrenth(int changeValue, CardButton *target, bool sendmsg)
{
    target->card->currentCombatValue += changeValue;
    CardSlot* parent = dynamic_cast<CardSlot*>(target->parentWidget());
    strenth[parent] += changeValue;
    updateStrenthSum();
    if (sendmsg)
    {
        QMap<QString, QString> msg;
        msg["type"] = QString::number(MCHANGESTRENTH);
        msg["value"] = QString::number(changeValue);
        msg["parent"] = parent->objectName();
        msg["card"] = QString::number(target->card->index);
        emit sendMsg(msg);
    }
}

void BattleField::updateStrenthSum()
{
    mStrenth = strenth[mBack] + strenth[mMiddle] + strenth[mFront];
    oStrenth = strenth[oBack] + strenth[oMiddle] + strenth[oFront];
    ui->gamingMBS->setText(QString::number(strenth[mBack]));
    ui->gamingMMS->setText(QString::number(strenth[mMiddle]));
    ui->gamingMFS->setText(QString::number(strenth[mFront]));
    ui->gamingMSum->setText(QString::number(mStrenth));
    ui->gamingOBS->setText(QString::number(strenth[oBack]);
    ui->gamingOMS->setText(QString::number(strenth[oMiddle]));
    ui->gamingOFS->setText(QString::number(strenth[oFront]));
    ui->gamingOSum->setText(QString::number(oStrenth));
}

QList<CardButton*> BattleField::drawCards(int count)
{
    QList<CardButton*> drawnCards;
    for (int i = 0; i< count; i++) {
        if (mDeck.isEmpty())
        {
            break;
        }
        drawnCards.append((new CardButton(mDeck.takeFirst(), this, this)));
    }
    return drawnCards;
}

void BattleField::addCardToMDeck(int id)
{
    mDeck.append(id);
}

