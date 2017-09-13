#ifndef CARD_H
#define CARD_H

#include "cardEnum.h"
#include "w_battlefield.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <QObject>

class CardButton;

class Card : public QObject
{
    Q_OBJECT

public:
    const int id;
    const int basisCombatValue;
    const QString name;
    const QString functionDeclaration;
    const QString iconUrl;
    QVector<EPosition> position;
    const EQuality quality;
    const EClassification classification;
    QVector<EProperty> property;

    int index{-1};
    bool belongtome{true};
    int currentCombatValue;
    int armor{0};
    BattleField * battleField;
    CardButton * button{nullptr};
public:
    explicit Card(int id,
                  int basisCombatValue,
                  QString name,
                  QString functionDeclaration,
                  QString iconUrl,
                  EQuality quality,
                  EClassification classification,
                  BattleField * battleField = nullptr,
                  QObject *parent = nullptr);
    virtual void exertAbility() = 0;
    void choosePosition(QList<int> chooseableSlot);
private slots:
    virtual void afterChoosePosition(CardSlot* slot);
    ~Card();
friend class CardButton;
};

#endif // CARD_H
