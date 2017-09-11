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

void BattleField::init(CardSet *cardset, Ui::MainWindow *aui)
{
    mCardSet = cardset;
    ui = aui;
    mleader = new CardButton(mCardSet->leader, this, ui->gamingMLeader);
    mleader->show();
    mDeck = mCardSet->allCards;
    mDeck.removeOne(mCardSet->leader);
    shuffle();

}

void BattleField::dispatchCard(CardButton * card)
{
    ui->gamingChooseSlot->setAllEnabled(false);
    int index = ui->gamingChooseSlot->getIndex(card);
    ui->gamingChooseSlot->addCard(drawCards().first(), index);
    signalTimes++;
    if (signalTimes < signalTimesLimit)
    {
        ui->gamingChooseSlot->setAllEnabled(true);
    }
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(changePageToGaming()), Qt::UniqueConnection);
    connect(timer, SIGNAL(timeout()), timer, SLOT(deleteLater()), Qt::UniqueConnection);
    timer->start(1000);
}

void BattleField::changePageToGaming()
{
    ui->gamingChooseSlot->clear();
    ui->gameStackWidget->setCurrentIndex(PGAMING);
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

void BattleField::showToBechosen(QList<CardButton *> list, standardSlot slot)
{
    for (auto it: list) {
        ui->gamingChooseSlot->addCard(&*it);
        connect(&*it, &CardButton::seletced, this, slot);
    }
    ui->gameStackWidget->setCurrentIndex(PCHOOSE);
}
