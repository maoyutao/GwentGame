#include "game.h"

Game::Game(Player * player, QObject *parent) : QObject(parent), mPlayer(player),
    battleField(new BattleField(player->cardSets.value(player->chosenSet), this))
{

}
