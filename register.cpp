#include "cards.h"
#include "ui_cardsetbutton.h"

#define REGISTER_CARD(id) \
class RegisterCard##id\
{\
public:\
    static void* createCard(BattleField * BattleField = nullptr, QObject *parent = nullptr)\
    {\
        return new Card_##id(BattleField, parent);\
    }\
private:\
    static Register reg;\
};\
Register RegisterCard##id::reg = Register(id, RegisterCard##id::createCard);

// 静态成员初始化
QMap<int, newCardFunctionPtr> CardFactory::cardMap;
int CardSetButton::unique = 0;

// 注册卡牌
REGISTER_CARD(0)
REGISTER_CARD(1)
REGISTER_CARD(2)
REGISTER_CARD(3)
REGISTER_CARD(4)
REGISTER_CARD(5)
REGISTER_CARD(6)
REGISTER_CARD(7)
REGISTER_CARD(8)
REGISTER_CARD(9)
REGISTER_CARD(10)
REGISTER_CARD(11)
REGISTER_CARD(12)
REGISTER_CARD(13)
REGISTER_CARD(14)
REGISTER_CARD(15)
REGISTER_CARD(16)
REGISTER_CARD(17)
REGISTER_CARD(18)
REGISTER_CARD(19)
REGISTER_CARD(20)
REGISTER_CARD(21)
REGISTER_CARD(22)
