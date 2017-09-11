#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    allCards << 0 << 1 << 2 << 2 << 3 << 4 << 5 << 5 << 6 << 7 << 8 << 9 << 10
             << 11 << 11 << 13 << 2 << 13 << 13 << 16 << 17 << 17 << 17 << 19 << 21
             << 21 << 22 << 23;
    QList<int> DagonSetCards;
    DagonSetCards << 0 << 1 << 2 << 2 << 3 << 4 << 5 << 4 << 6 << 7 << 8 << 9 << 10
                  << 11 << 11 << 13 << 2 << 13 << 13 << 16 << 17 << 17 << 17 << 19 << 21
                  << 21 << 22 << 23;
    cardSets.append(new CardSet("DagonSet", DagonSetCards));
    QList<int> UnseenElderSetCards;
    UnseenElderSetCards<< 0 << 1 << 2 << 2 << 3 << 4 << 5 << 5 << 6 << 7 << 20 << 9 << 10
                       << 11 << 11 << 13 << 14 << 15 << 16 << 16 << 17 << 17 << 19 << 19 << 21
                       << 21 << 22 << 23;
    cardSets.append(new CardSet("UnseenElderSet", UnseenElderSetCards));
}
