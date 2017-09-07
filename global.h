#ifndef GLOBAL_H
#define GLOBAL_H

#define PStartIndex 0
#define PChooseIndex 1
#define PChooseEditCcardsIndex 2
#define PEditCardsIndex 3
#define PGameReadyIndex 4
#define PDispacthCardsIndex 5
#define PGamingIndex 6
#define PScore 7
#define PFinalScore 8

#define REGISTER_CARD(id) \
void* createCard##id(BattleField * BattleField = nullptr, QObject *parent = nullptr)\
{\
    return new card##id;\
}\
CardFactory::RegisterClass(id, createCard##id);


enum class EPosition
{
    mFront,
    mMiddle,
    mBack,
    oFront,
    oMiddle,
    oBack,
    Null,
};

enum class EQuality
{
    Gold,
    Silver,
    Copper,
};

enum class EClassification
{
    Leader,
    Unit,
    Event,
};

enum class EProperty
{
    Special,
};
#endif // GLOBAL_H
