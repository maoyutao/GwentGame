#include "w_battlefield.h"
#include "cards.h"
#include "cardset.h"
#include "ui_cardbutton.h"
#include "ui_mainwindow.h"
#include <QTimer>

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
        ui->mHandSlot->addCard(&*it);
        allCards.append(dynamic_cast<CardButton*>(&*it));
    }
    ui->mHandSlot->setCurrentIndex(0);

    // init opponent's hand slot
    for (int i = 0; i < 10; i++)
    {
        ui->oHandSlot->addCard(new CardButton(-1, nullptr, ui->oHandSlot));
    }
    ui->oHandSlot->setCurrentIndex(0);

    CardButton* oleader = new CardButton(-1, nullptr, ui->gamingOLeader);
    oleader->raise();
    mleader->show();
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

