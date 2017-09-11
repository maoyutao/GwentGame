#ifndef CARDSET_H
#define CARDSET_H

#include <QList>

class CardSet
{
public:
    CardSet(QString name, QList<int> allCards);
    CardSet(QString name);
    QString name;
    QList<int> allCards;
    int leader{-1};
    QString leaderName;
    QString cover{":/new/prefix1/resource/cardSet.png"};
    QString info;
    bool isValid{false};
private:
    void updateInfo();
    void update();
};

#endif // CARDSET_H
