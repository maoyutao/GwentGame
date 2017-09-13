#include "w_battlefield.h"
#include "cards.h"
#include "cardset.h"
#include "ui_cardbutton.h"
#include "ui_mainwindow.h"
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

void BattleField::initForFirst(Ui::MainWindow *aui)
{
    ui = aui;
    mFront = ui->gamingMFront;
    mMiddle = ui->gamingMMiddle;
    mBack = ui->gamingMBcak;
    oFront = ui->gamingOFront;
    oMiddle = ui->gamingOMiddle;
    oBack = ui->gamingOBack;
    mHand = ui->mHandSlot;
    oHand = ui->oHandSlot;
    cardSlot.append(mFront);
    cardSlot.append(mMiddle);
    cardSlot.append(mBack);
    cardSlot.append(oFront);
    cardSlot.append(oMiddle);
    cardSlot.append(oBack);
}

void BattleField::setCardSet(CardSet *cardset)
{
    mCardSet = cardset;
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
        p->exertable = false;
    }
    mHand->setCurrentIndex(0);

    // init opponent's hand slot
    for (int i = 0; i < 10; i++)
    {
        addCardToOhand();
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
    int index = qrand() % mHand->cardList.count();
    dynamic_cast<CardButton*>(mHand->cardList.at(index))->card->exertAbility();
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

void BattleField::move(CardSlot *to, CardButton *card, bool sendmsg)
{
    // from range: 六排 空（敌人的手牌打出来的是空） 我的手牌  to range: 六排 （我自己发动的时候的）空 我的手牌 敌人发动的时候不会到我的手牌里
    // 完成了： 如果原有父亲就拿出 如果需注册但还未注册就注册 如果相关分数就改分数
    Msg msg;
    msg["fromEmpty"] = QString::number(0); // fromempty 和fromhand 是没有编号的
    msg["fromhand"] = QString::number(0);
    msg["tohand"] = QString::number(0);
    int mstrenth = card->card->currentCombatValue;
    if (card->slot)
    {
        CardSlot* from = card->slot;
        qDebug() << from;
        qDebug() << mHand;
        qDebug() << oHand;
        from->removeCard(card);
        if (strenth.contains(from))
        {
            strenth[from] -= mstrenth;
        }
        if (card->slot == mHand)
        {
            msg["fromhand"] = QString::number(1);
        }

    } else {
        msg["fromEmpty"] = QString::number(1);
    }
    if (to)
    {
        to->addCard(card);
    }
    if (strenth.contains(to))
    {
        strenth[to] -= mstrenth;
        if (card->card->index == -1)
        {
            card->card->index = cardsOnBoard.count();
            cardsOnBoard.append(card);
        }
    } else {
        msg["tohand"] = QString::number(1);
    }
    updateStrenthSum();
    if (sendmsg)
    {
        msg["type"] = "move";
        msg["to"] = QString::number(cardSlot.indexOf(to));
        msg["toslot"] = QString::number(1);
        msg["index"] = QString::number(card->card->index);
        msg["id"] = QString::number(card->card->id);
        emit sendMsg(msg);
    }
}

void BattleField::move(QString to, CardButton *card, bool sendmsg)
{
    // from range: 六排 空（敌人的手牌分成从手牌取一张（上层做） 和从一张空move两部分） 我的手牌  to range: 墓地 牌组
    // 完成了： 如果原有父亲就拿出 如果相关分数就改分数
    Msg msg;
    msg["tohand"] = QString::number(0);
    int mstrenth = card->card->currentCombatValue;
    if (card->slot)
    {
        if (card->slot == mHand)
        {
            msg["fromhand"] = QString::number(1);
        }
        CardSlot* from = dynamic_cast<CardSlot*>(card->slot);
        from->removeCard(card);
        if (strenth.contains(from))
        {
            strenth[from] -= mstrenth;
        }
    } else {
        msg["fromEmpty"] = QString::number(1);
    }
    card->deleteLater();
    if (to == "cemetery")
    {
        mCemetery.append(card->card->id);
    } else if (to == "deck")
    {
        addCardToMDeck(card->card->id);
    }
    updateStrenthSum();
    if (sendmsg)
    {
        msg["type"] = "move";
        msg["to"] = to;
        msg["toslot"] = QString::number(0);
        msg["index"] = QString::number(card->card->index);
        msg["id"] = QString::number(card->card->id);
        emit sendMsg(msg);
    }
}

void BattleField::changeStrenth(int changeValue, CardButton *target, bool sendmsg)
{
    target->card->currentCombatValue += changeValue;
    CardSlot* parent = dynamic_cast<CardSlot*>(target->slot);
    strenth[parent] += changeValue;
    updateStrenthSum();
    if (sendmsg)
    {
        Msg msg;
        msg["type"] = "changeStrenth";
        msg["value"] = QString::number(changeValue);
        msg["index"] = QString::number(target->card->index);
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
    ui->gamingOBS->setText(QString::number(strenth[oBack]));
    ui->gamingOMS->setText(QString::number(strenth[oMiddle]));
    ui->gamingOFS->setText(QString::number(strenth[oFront]));
    ui->gamingOSum->setText(QString::number(oStrenth));
}

void BattleField::addCardToOhand()
{
    CardButton* c = new CardButton(-1, nullptr, oHand);
    c->setEnabled(false);
    oHand->addCard(c);
}

void BattleField::removeCardFromOhand()
{
    oHand->removeCard();
}

void BattleField::drawCardTohand()
{
    move(mHand, drawCards(1).first());
    Msg msg;
    msg["type"] = "ohandChange";
    msg["change"] = QString::number(1);
    sendMsg(msg);
}

QList<CardButton*> BattleField::drawCards(int count)
{
    QList<CardButton*> drawnCards;
    for (int i = 0; i< count; i++) {
        if (mDeck.isEmpty())
        {
            break;
        }
        CardButton* c = new CardButton(mDeck.takeFirst(), this, nullptr);
//        c->setInfoBox(ui->bigBox);
        drawnCards.append(c);
    }
    return drawnCards;
}

QList<CardButton *> BattleField::drawCards(int count, int except)
{
    int num = mDeck.removeAll(except);
    QList<CardButton*> drawnCards;
    for (int i = 0; i< count; i++) {
        if (mDeck.isEmpty())
        {
            break;
        }
        CardButton* c = new CardButton(mDeck.takeFirst(), this, nullptr);
//        c->setInfoBox(ui->bigBox);
        drawnCards.append(c);
    }
    for (int i = 0; i < num; i++)
    {
        mDeck.append(except);
    }
    shuffle();
    return drawnCards;
}

void BattleField::addCardToMDeck(int id)
{
    mDeck.append(id);
    shuffle();
}


