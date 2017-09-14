#include "ui_timerround.h"
#include <QDebug>

TimerRound::TimerRound(QWidget *parent) : QLabel(parent), timer(new QTimer(this)), record(new QTime(0, 0, 59))
{
}


void TimerRound::start(bool isMyRound)
{
    if (isMyRound)
    {
        current = 1;
    } else {
        current = 0;
    }
    this->setStyleSheet(styleSheet[current]);
    timer->start(1000);
    record->setHMS(0, 0, 59);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()), Qt::UniqueConnection);
}

void TimerRound::change()
{
    current = (current + 1) % 2;
    this->setStyleSheet(styleSheet[current]);
    record->setHMS(0, 0, 59);
    timer->start(1000);

    qDebug() << "change" << styleSheet[current];
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

void TimerRound::mouseDoubleClickEvent(QMouseEvent *)
{
    emit giveup();
}
