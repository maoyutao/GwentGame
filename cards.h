#ifndef CARD_H
#define CARD_H

#include "global.h"
#include "battlefield.h"
#include <QObject>
#include <QString>
#include <QPixmap>
#include <QVector>

class Card : public QObject
{
    Q_OBJECT

private:
    const int id;
    const int basisCombatValue;
    const QString name;
    const QString functionDeclaration;
    const QPixmap icon;
    const QVector<EPosition> position;
    const EQuality quality;
    const EClassification classification;
    const QVector<EProperty> Property;

    int currentCombatValue;
    int armor{0};
    BattleField * mBattleField;
//    virtual void exertAbility();
public:
    explicit Card(int id,
                  int basisCombatValue,
                  QString name,
                  QString functionDeclaration,
                  QPixmap icon,
                  QVector<EPosition> position,
                  EQuality quality,
                  EClassification classification,
                  QVector<EProperty> Property,
                  BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);

signals:

public slots:
};

#endif // CARD_H
