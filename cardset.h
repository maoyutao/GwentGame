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
    QString cover{":/new/cards/resource/cards/card_20.png"};

    bool isValidate();
};

#endif // CARDSET_H
