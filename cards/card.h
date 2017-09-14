#ifndef CARD_H
#define CARD_H

#include "cardEnum.h"
#include <QObject>
#include <QString>
#include <QVector>
#include <QObject>

#define SLOTMFRONT 0
#define SLOTMMMIDLE 1
#define SLOTMBACK 2
#define SLOTOFRONT 3
#define SLOTOMMIDLE 4
#define SLOTOBACK 5

class CardButton;
class BattleField;
class CardSlot;

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
    bool first{true};
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
    virtual void dyingWish();
    void choosePosition(QList<int> chooseableSlot);
    void chooseCardOnBoard(QList<int> chooseableCard);
private:
    QList<int> mChooseableSlot;
    QList<int> mChooseableCard;
protected slots:
    virtual void afterChoosePosition(CardSlot* slot);
    void basicAfterChoosePosition();
    virtual void afterChooseCard(CardButton* slot);
    void basicAfterChooseCard();
friend class CardButton;
};

#endif // CARD_H
