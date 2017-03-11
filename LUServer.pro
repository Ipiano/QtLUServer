QT += core network
QT -= gui

CONFIG += c++11

TARGET = LUServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

TMPPWD = $$replace(PWD," ","_")

HEADERS += \
    DataBrokers/databroker.h \
    DataBrokers/filebroker.h \
    MessageHandlers/rakmessagehandler.h \
    MessageHandlers/luauthserverhandler.h \
    MessageHandlers/lugameserverhandler.h \
    luserver.h \
    logger.h \
    messageheaders.h \
    useraccounts.h \
    sha512.hh \
    bytestream.h \
    GameLogic/gamelogic.h

SOURCES += main.cpp \
    DataBrokers/databroker.cpp \
    DataBrokers/filebroker.cpp \
    MessageHandlers/rakmessagehandler.cpp \
    MessageHandlers/luauthserverhandler.cpp \
    MessageHandlers/lugameserverhandler.cpp \
    luserver.cpp \
    logger.cpp \
    GameLogic/gamelogic.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include($$TMPPWD/QtRakNet/qtraknet.pri)

TMPPWD = $$replace(PWD," ","_")

LIBS += -L$$LIB_DIR -lws2_32
CONFIG(debug, debug|release){
    LIBS += -lQtRakNet_d -lConsoleThread_d
    DESTDIR = $$TMPPWD/debug
}else{
    LIBS += -lQtRakNet -lConsoleThread
    DESTDIR = $$TMPPWD/release
}

