#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

class Player : public QObject
{
    Q_OBJECT
private:
    int point{0};
    QList<int> allCards;
public:
    explicit Player(QObject *parent = nullptr);
    QMap<QString, QList<int>> cardSets;
    QString chosenSet;
signals:

public slots:
};

#endif // PLAYER_H
