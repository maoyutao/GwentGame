#include "game.h"

Game::Game(Player * player, CardSet* cardSet, QObject *parent) : QObject(parent), mPlayer(player),
    battleField(new BattleField(cardSet->allCards, this))
{

}
