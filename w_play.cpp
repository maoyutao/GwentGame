#include "w_play.h"
#include "ui_mainwindow.h"

Play::Play(QWidget *parent) : QStackedWidget(parent)
{

}

void Play::init(Player *aPlayer, Ui::MainWindow *aui)
{
    ui = aui;
    player = aPlayer;
    this->setCurrentIndex(0);
}
