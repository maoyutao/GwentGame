#include "cards.h"
#include <QDebug>

void Card::exertAbility()
{
}

Card::Card(int id,
           int basisCombatValue,
           QString name,
           QString functionDeclaration,
           QString iconUrl,
           EQuality quality,
           EClassification classification,
           BattleField * battleField,
           QObject *parent
           ):QObject(parent),
            id(id),
            basisCombatValue(basisCombatValue),
            name(name),
            functionDeclaration(functionDeclaration),
            iconUrl(iconUrl),
            quality(quality),
            classification(classification),
            currentCombatValue(basisCombatValue),
            battleField(battleField)
{

}

Card::~Card()
{
//    qDebug() << "delete Card" <<id;
}

Card_0::Card_0(BattleField *battleField, QObject *parent):
    Card(0, 0, "First Light", "生成“晴空”或“重整”。", ":/new/cards/resource/cards/card_0.png", EQuality::Copper,
         EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Special);
}

void Card_0::exertAbility(){
    battleField->move(battleField->mBack, this->button);
}




Card_3::Card_3(BattleField *battleField, QObject *parent):
    Card(3, 0, "Torrential Rain", "在对方单排降下“倾盆大雨”。倾盆大雨：每当己方回合开始时，对所在排最多 2 个随机单位造成 1 点伤害。", ":/new/cards/resource/cards/card_3.png",
         EQuality::Copper, EClassification::Event, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);
    property.append(EProperty::Special);
    property.append(EProperty::Weather);
}

Card_4::Card_4(BattleField *battleField, QObject *parent):
    Card(4, 0, "Lacerate", "对单排所有单位造成 3 点伤害。", ":/new/cards/resource/cards/card_4.png",
        EQuality::Copper, EClassification::Event, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);
    property.append(EProperty::Organisms);
    property.append(EProperty::Special);
}

Card_5::Card_5(BattleField *battleField, QObject *parent):
    Card(5, 0, "Commander's Horn", "使 5 个相邻单位获得 4 点增益。", ":/new/cards/resource/cards/card_5.png",
         EQuality::Silver, EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Strategy);
    property.append(EProperty::Special);
}

Card_6::Card_6(BattleField *battleField, QObject *parent):
    Card(6, 0, "Bekker's Twisted Mirror", "对场上最强的单位造成数值等同于其战力的伤害，但最多不超过 10 点（无视护甲），并使场上最弱的非同名单位获得相同数值的增益。",
         ":/new/cards/resource/cards/card_6.png",
         EQuality::Silver, EClassification::Event, battleField, parent)
{
    position.append(EPosition::Null);
    property.append(EProperty::Magic);
    property.append(EProperty::Special);
}

Card_7::Card_7(BattleField *battleField, QObject *parent):
    Card(7, 5, "Geralt: Igni", "部署：若对方同排总战力不低于 25 ，则摧毁其上所有最强的单位。", ":/new/cards/resource/cards/card_7.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Hunter);
}

Card_8::Card_8(BattleField *battleField, QObject *parent):
    Card(8, 6, "Dagon", "佚亡、坚守。部署：生成“刺骨冰霜”、“蔽日浓雾”或“倾盆大雨”。", ":/new/cards/resource/cards/card_8.png",
         EQuality::Gold, EClassification::Leader, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Aquatic);
}

Card_9::Card_9(BattleField *battleField, QObject *parent):
    Card(9, 4, "Foglet", "每当己方“蔽日浓雾”在敌排生效，便从牌组打出 1 个“小雾妖”至己方同排。若牌组中没有“小雾妖”，则复活 1 个“小雾妖”至己方同排。若场上不再存在“蔽日浓雾”效果，则摧毁所有“小雾妖”。",
         ":/new/cards/resource/cards/card_9.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Scavengers);
}

Card_10::Card_10(BattleField *battleField, QObject *parent):
    Card(10, 1, "Ge'els", "部署：从牌组顶端各抽 1 张金色牌和银色牌。打出 1 张，将另 1 张置于牌组顶端。",
         ":/new/cards/resource/cards/card_10.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Officer);
    property.append(EProperty::WildHunt);
}

Card_11::Card_11(BattleField *battleField, QObject *parent):
    Card(11, 5, "Celaeno Harpy", "部署：在自身左侧生成 2 个“鹰身女妖蛋”。",
         ":/new/cards/resource/cards/card_11.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Beast);
}

Card_12::Card_12(BattleField *battleField, QObject *parent):
    Card(12, 5, "Woodland Spirit", "部署：生成 3 只“暴怒的狼”，并在对方同排降下“蔽日浓雾”。",
         ":/new/cards/resource/cards/card_12.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Beast);
}

Card_13::Card_13(BattleField *battleField, QObject *parent):
    Card(13, 6, "Earth Elemental", "部署：获得护盾。遗愿：在该排末位生成 2 个“次级土元素”。",
         ":/new/cards/resource/cards/card_13.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    property.append(EProperty::Tectosome);
}

Card_14::Card_14(BattleField *battleField, QObject *parent):
    Card(14, 6, "Crone: Weavess", "部署：从牌组打出“煮婆”和“呢喃婆”。",
         ":/new/cards/resource/cards/card_14.png",
         EQuality::Silver, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::Waste);
}

Card_15::Card_15(BattleField *battleField, QObject *parent):
    Card(15, 6, "Crone: Whispess", "部署：从牌组打出“煮婆”和“织婆”。",
         ":/new/cards/resource/cards/card_15.png",
         EQuality::Silver, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::Waste);
}

Card_16::Card_16(BattleField *battleField, QObject *parent):
    Card(16, 8, "Crone: Brewess", "部署：从牌组打出“呢喃婆”和“织婆”。",
         ":/new/cards/resource/cards/card_16.png",
         EQuality::Silver, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::Waste);
}

Card_17::Card_17(BattleField *battleField, QObject *parent):
    Card(17, 8, "Archgriffin", "部署：移除所在排的天气效果。将 1 张铜色牌从一方墓场置入另一方墓场",
         ":/new/cards/resource/cards/card_17.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Beast);
}

Card_18::Card_18(BattleField *battleField, QObject *parent):
    Card(18, 8, "Caranthir", "部署：将 1 个敌军单位移至其所在半场同排，并在此排降下“刺骨冰霜”。",
         ":/new/cards/resource/cards/card_18.png",
         EQuality::Gold, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Magic);
    property.append(EProperty::WildHunt);
}

Card_19::Card_19(BattleField *battleField, QObject *parent):
    Card(19, 12, "Frightener", "佚亡。部署：从牌组顶端抽 1 张牌。将所在战场其他排的 1 个单位移至自身的同一排。",
         ":/new/cards/resource/cards/card_19.png",
         EQuality::Silver, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::oFront);
    position.append(EPosition::oMiddle);
    position.append(EPosition::oBack);
    property.append(EProperty::Spy);
    property.append(EProperty::Tectosome);
}

Card_20::Card_20(BattleField *battleField, QObject *parent):
    Card(20, 5, "Unseen Elder", "佚亡、坚守。部署：吞噬 3 个友军单位，吸收它们的战力为自身的基础战力。",
         ":/new/cards/resource/cards/card_20.png",
         EQuality::Gold, EClassification::Leader, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Vampire);
}

Card_21::Card_21(BattleField *battleField, QObject *parent):
    Card(21, 3, "Arachas", "部署：从牌组打出所有“蟹蜘蛛”。",
         ":/new/cards/resource/cards/card_21.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Worm);
}

Card_22::Card_22(BattleField *battleField, QObject *parent):
    Card(22, 6, "Vran Warrior", "部署：吞噬右侧单位。每 2 回合，己方回合开始时，吞噬右侧单位。",
         ":/new/cards/resource/cards/card_22.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mFront);
    position.append(EPosition::mMiddle);
    position.append(EPosition::mBack);
    property.append(EProperty::Drake);
}

Card_23::Card_23(BattleField *battleField, QObject *parent):
    Card(23, 6, "Arachas Behemoth", "每当有友军单位吞噬 1 张牌，便生成 1 只“蟹蜘蛛幼虫”，随后受到 1 点伤害（无视护甲）。部署：获得 2 点护甲。",
         ":/new/cards/resource/cards/card_23.png",
         EQuality::Copper, EClassification::Unit, battleField, parent)
{
    position.append(EPosition::mBack);
    property.append(EProperty::Worm);
}
