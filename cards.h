#ifndef CARD_H
#define CARD_H

#include "global.h"
#include "battlefield.h"
#include <QObject>
#include <QString>
#include <QPixmap>
#include <QVector>

class CardButton;
class Card : public QObject
{
    Q_OBJECT

private:
    const int id;
    const int basisCombatValue;
    const QString name;
    const QString functionDeclaration;
    const QString iconUrl;
    const QVector<EPosition>* position;
    const EQuality quality;
    const EClassification classification;
    const QVector<EProperty>* Property;

    int currentCombatValue;
    int armor{0};
    BattleField * battleField;
//    virtual void exertAbility();
public:
    explicit Card(int id,
                  int basisCombatValue,
                  QString name,
                  QString functionDeclaration,
                  QString iconUrl,
                  QVector<EPosition>* position,
                  EQuality quality,
                  EClassification classification,
                  QVector<EProperty>* Property,
                  BattleField * battleField = nullptr,
                  QObject *parent = nullptr);

signals:

public slots:

friend class CardButton;
};

class Card_0 : public Card
{
public:
    explicit Card_0(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
};

#endif // CARD_H
