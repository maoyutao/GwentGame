#include "player.h"

Player::Player(QObject *parent) : QObject(parent)
{
    allCards << 0 << 1 << 2 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10;
    cardSets["DagonSet"] << 0 << 1 << 2 << 2 << 3 << 4;
    cardSets["UnseenElderSet"] << 4 << 5 << 6 << 7 << 8 << 9 << 10;
    chosenSet = "DagonSet";
}
