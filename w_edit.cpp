#include "w_edit.h"

Edit::Edit(QWidget *parent) : QStackedWidget(parent)
{

}

void Edit::init(Player *player)
{
    player = player;
    this->setCurrentIndex(0);
}
