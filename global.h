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
    Special, // 特殊
    Weather, // 天气
    Organisms, // 生物
    Strategy, // 谋略
    Magic, // 法术
    Hunter, // 猎魔人
    Aquatic, // 水生
    Officer, // 军官
    WildHunt, // 狂猎
    Beast, // 野兽
    Waste, // 残物
    Tectosome, // 构造体
    Spy, // 密探
    Vampire, // 吸血鬼
    Worm, // 类虫
    Drake, //龙兽
    Scavengers, // 食腐
};
#endif // GLOBAL_H
