#ifndef UI_TIMERROUND_H
#define UI_TIMERROUND_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QTime>

class TimerRound : public QLabel
{
    Q_OBJECT
public:
    explicit TimerRound(QWidget *parent = nullptr);

signals:
    void timeout();
public slots:
    void start(bool isMyRound);
    void change();
private:
    int current{0};
    QTimer* timer;
    QTime * record;
    QString styleSheet[2]{"border-image: url(:/new/prefix1/resource/o_round_circle.png)",
                          "border-image: url(:/new/prefix1/resource/m_round_circle.png)"};
private slots:
    void updateTime();
};

#endif // UI_TIMERROUND_H
