#-------------------------------------------------
#
# Project created by QtCreator 2017-09-05T20:55:36
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gwent
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    player.cpp \
    cardfactory.cpp \
    register.cpp \
    ui_cardbutton.cpp \
    ui_standardbutton.cpp \
    ui_cardslot.cpp \
    ui_tonextpagebutton.cpp \
    ui_toprepagebutton.cpp \
    w_edit.cpp \
    cardset.cpp \
    ui_cardsetbutton.cpp \
    ui_standarddialog.cpp \
    w_game.cpp \
    w_battlefield.cpp \
    ui_timerround.cpp \
    cards/card_0.cpp \
    cards/card.cpp \
    cards/card_1.cpp \
    cards/card_3.cpp \
    cards/card_2.cpp \
    cards/card_4.cpp \
    cards/card_5.cpp \
    cards/card_6.cpp \
    cards/card_7.cpp \
    cards/card_8.cpp \
    cards/card_9.cpp \
    cards/card_10.cpp \
    cards/card_11.cpp \
    cards/card_12.cpp \
    cards/card_13.cpp \
    cards/card_14.cpp \
    cards/card_15.cpp \
    cards/card_16.cpp \
    cards/card_17.cpp \
    cards/card_18.cpp \
    cards/card_19.cpp \
    cards/card_20.cpp \
    cards/card_21.cpp \
    cards/card_22.cpp \
    cards/card_23.cpp \
    cards/card_24.cpp \
    cards/card_25.cpp

HEADERS += \
        mainwindow.h \
    player.h \
    cardfactory.h \
    ui_cardbutton.h \
    ui_standardbutton.h \
    ui_cardslot.h \
    ui_tonextpagebutton.h \
    ui_toprepagebutton.h \
    cardEnum.h \
    w_edit.h \
    cardset.h \
    ui_cardsetbutton.h \
    ui_standarddialog.h \
    w_game.h \
    w_battlefield.h \
    ui_timerround.h \
    cards/card_0.h \
    cards/index.h \
    cards/card.h \
    cards/card_1.h \
    cards/card_3.h \
    cards/card_2.h \
    cards/card_4.h \
    cards/card_5.h \
    cards/card_6.h \
    cards/card_7.h \
    cards/card_8.h \
    cards/card_9.h \
    cards/card_10.h \
    cards/card_11.h \
    cards/card_12.h \
    cards/card_13.h \
    cards/card_14.h \
    cards/card_15.h \
    cards/card_16.h \
    cards/card_17.h \
    cards/card_18.h \
    cards/card_19.h \
    cards/card_20.h \
    cards/card_21.h \
    cards/card_22.h \
    cards/card_23.h \
    cards/card_24.h \
    cards/card_25.h

FORMS += \
        mainwindow.ui \
    dialog.ui

RESOURCES += \
    ui.qrc

DISTFILES +=

