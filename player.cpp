#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    allCards << 0 << 1 << 2 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;
    QList<int> DagonSetCards;
    DagonSetCards << 0 << 1 << 2 << 2 << 3 << 4;
    cardSets.append(new CardSet("DagonSet", DagonSetCards));
//    QList<int> UnseenElderSetCards;
//    UnseenElderSetCards<< 4 << 5 << 6 << 7 << 8 << 9 << 10;
//    cardSets.append(new CardSet("UnseenElderSet", UnseenElderSetCards));
}
