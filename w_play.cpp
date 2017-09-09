#include "w_play.h"

Play::Play(QWidget *parent) : QStackedWidget(parent)
{

}

void Play::init(Player *player)
{
    player = player;
    game = new Game(player, this);
    this->setCurrentIndex(0);
}
