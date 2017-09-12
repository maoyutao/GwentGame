#include "ui_timerround.h"
#include <QDebug>

TimerRound::TimerRound(QWidget *parent) : QLabel(parent), timer(new QTimer(this)), record(new QTime(0, 0, 60))
{
}

void TimerRound::start(bool isMyRound)
{
    if (isMyRound)
    {
        current = 0;
    } else {
        current = 1;
    }
    this->setStyleSheet(styleSheet[current]);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
}

void TimerRound::change()
{
    current = (current + 1) % 2;
    this->setStyleSheet(styleSheet[current]);
    record->setHMS(0, 0, 60);
    timer->start(1000);
}

void TimerRound::updateTime()
{
    *record = record->addSecs(-1);
    this->setText(record->toString("ss"));
    if (*record == QTime(0, 0, 0))
    {
        emit timeout();
        timer->stop();
    }
}
