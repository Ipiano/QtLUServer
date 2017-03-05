TEMPLATE = subdirs

SUBDIRS = \
    qtRakNet \
    luServer \
    consoleThread

TMPPWD = $$replace(PWD," ","_")

qtRakNet.file = $$TMPPWD/QtRakNet/QtRakNet.pro
luServer.file = $$TMPPWD/LUServer.pro
consoleThread.file = $$TMPPWD/QtRakNet/ConsoleThread/ConsoleThread.pro

luServer.depends = qtRakNet consoleThread
