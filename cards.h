#ifndef CARD_H
#define CARD_H

#include "cardEnum.h"
#include "w_battlefield.h"
#include "cardfactory.h"
#include <QObject>
#include <QString>
#include <QPixmap>
#include <QVector>

#define DECLARE_CARD(id)\
class Card_##id : public Card\
{\
public:\
    explicit Card_##id(BattleField * BattleField = nullptr,\
                  QObject *parent = nullptr);\
private:\
};

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

    int currentCombatValue;
    int armor{0};
    BattleField * battleField;
    CardButton * button{nullptr};
    virtual void exertAbility();
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
    ~Card();
friend class CardButton;
};

class Card_0 : public Card
{
public:
    explicit Card_0(BattleField * BattleField = nullptr,
                  QObject *parent = nullptr);
private:
    void exertAbility() override;
};

DECLARE_CARD(1)
DECLARE_CARD(2)
DECLARE_CARD(3)
DECLARE_CARD(4)
DECLARE_CARD(5)
DECLARE_CARD(6)
DECLARE_CARD(7)
DECLARE_CARD(8)
DECLARE_CARD(9)
DECLARE_CARD(10)
DECLARE_CARD(11)
DECLARE_CARD(12)
DECLARE_CARD(13)
DECLARE_CARD(14)
DECLARE_CARD(15)
DECLARE_CARD(16)
DECLARE_CARD(17)
DECLARE_CARD(18)
DECLARE_CARD(19)
DECLARE_CARD(20)
DECLARE_CARD(21)
DECLARE_CARD(22)
DECLARE_CARD(23)
#endif // CARD_H
