#QT -= gui
QT += websockets
QT += widgets

CONFIG += c++11 console
#CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    Action.cpp \
    ActiveEffect.cpp \
    Attack.cpp \
    AttackDamage.cpp \
    BagItem.cpp \
    BagObject.cpp \
    BagPotion.cpp \
    BagWeapon.cpp \
    Character.cpp \
    Characteristics.cpp \
    CharacteristicsRange.cpp \
    DropItem.cpp \
    Effect.cpp \
    FightEndResult.cpp \
    FightManager.cpp \
    FightMap.cpp \
    InteractiveObject.cpp \
    Living.cpp \
    MapManager.cpp \
    MapObject.cpp \
    MapResource.cpp \
    MapTiles.cpp \
    Monster.cpp \
    MonsterTeam.cpp \
    Move.cpp \
    NonPlayer.cpp \
    ObjectDescriptor.cpp \
    ObjectFactory.cpp \
    Player.cpp \
    Point.cpp \
    Pos.cpp \
    Range.cpp \
    StartPos.cpp \
    StorageObject.cpp \
    Value.cpp \
    ValueRange.cpp \
    WebSocketClient.cpp \
    WebSocketServer.cpp \
    World.cpp \
    ConsoleClient.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES +=

HEADERS += \
    Action.h \
    Attack.h \
    Effect.h \
    ActiveEffect.h \
    AttackDamage.h \
    BagItem.h \
    BagObject.h \
    BagPotion.h \
    BagWeapon.h \
    Character.h \
    Characteristics.h \
    CharacteristicsRange.h \
    DropItem.h \
    MapObject.h \
    MapResource.h \
    MapTiles.h \
    Monster.h \
    MonsterTeam.h \
    Move.h \
    NonPlayer.h \
    ObjectDescriptor.h \
    ObjectFactory.h \
    Player.h \
    Point.h \
    Pos.h \
    Range.h \
    StorageObject.h \
    Value.h \
    WebSocketClient.h \
    WebSocketServer.h \
    World.h \
    FightEndResult.h \
    FightManager.h \
    InteractiveObject.h \
    Living.h \
    MapManager.h \
    ValueRange.h \
    StartPos.h \
    FightMap.h \
    ConsoleClient.h

FORMS += \
    BasicClientUI.ui
