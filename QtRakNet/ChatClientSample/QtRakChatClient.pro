QT += core
QT -= gui

CONFIG += c++11

TARGET = QtRakChatClient
CONFIG += console static
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#PWD Breaks on my win10 if you have spaces in your path (which I do)
#But I have a symbolic link set up which has the same path, just with _ instead of the space
#I should probably just change my user to not have a space...
TMPPWD = $$replace(PWD," ","_")

include($$TMPPWD/../qtraknet.pri)

LIBS += -L$$LIB_DIR -lws2_32
CONFIG(debug, debug|release){
    LIBS += -lQtRakNet_d -lConsoleThread_d
    DESTDIR = $$TMPPWD/debug
}else{
    LIBS += -lQtRakNet -lConsoleThread
    DESTDIR = $$TMPPWD/release
}
