#include "cardset.h"
#include "cards.h"
#include "cardEnum.h"
#include "cardfactory.h"
#include <QStringBuilder>
#include <QDebug>

CardSet::CardSet(QString name, QList<int> allCards): name(name), allCards(allCards)
{
    update();
    updateInfo();
}

CardSet::CardSet(QString name): name(name)
{
    update();
    updateInfo();
}

void CardSet::update()
{
    copper.clear();
    silver.clear();
    gold.clear();
    if (allCards.count() > 40) {
        isValid = false;
        return;
    }
    if (allCards.count() < 25) {
        isValid = false;
        return;
    }
    QList<int> leaders;
    for (auto it: allCards)
    {
        Card* card = static_cast<Card*>(CardFactory::CreateObject(it, nullptr, nullptr));
        switch (card->quality) {
        case EQuality::Copper:
            copper.append(card->id);
            break;
        case EQuality::Silver:
            silver.append(card->id);
            break;
        case EQuality::Gold:
            gold.append(card->id);
            break;
        default:
            break;
        }
        if (card->classification == EClassification::Leader)
        {
            leaders.append(card->id);
            leaderName = card->name;
        }
        delete card;
    }
    if (leaders.count() != 1) {
        isValid = false;
        return;
    } else {
        leader = leaders.at(0);
        updateInfo();
    }
    if (gold.count() > 4) {
        isValid = false;
        return;
    }
    if (silver.count() > 6) {
        isValid = false;
        return;
    }
    for (auto it: gold)
    {
        if (gold.count(it) > 1) {
            isValid = false;
            return;
        }
    }
    for (auto it: silver)
    {
        if (silver.count(it) > 1) {
            isValid = false;
            return;
        }
    }
    for (auto it: copper)
    {
        if (copper.count(it) > 3) {
            isValid = false;
            return;
        }
    }
    isValid = true;
    updateInfo();
}

void CardSet::updateInfo()
{
    QString mleader = (leader == -1) ? "null" : leaderName;
    QString mv = isValid ? "valid" : "invalid";
    info = "name: " % name % "\r\n"
            % "leader: " % mleader % "\r\n"
            % "gold:" % QString::number(gold.count()) % "\r\n"
            % "silver:" % QString::number(silver.count()) % "\r\n"
            % "copper:" % QString::number(copper.count()) % "\r\n"
            % mv;
}

