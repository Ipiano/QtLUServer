TEMPLATE = subdirs

SUBDIRS = \
    qtRakNet \
    chatServer \
    consoleThread

#PWD Breaks on my win10 if you have spaces in your path (which I do)
#But I have a symbolic link set up which has the same path, just with _ instead of the space
#I should probably just change my user to not have a space...
TMPPWD = $$replace(PWD," ","_")

chatServer.file = $$TMPPWD/ChatServerSample/QtRakChatServer.pro
qtRakNet.file = $$TMPPWD/QtRakNet.pro
consoleThread.file = $$TMPPWD/ConsoleThread/ConsoleThread.pro

chatServer.depends = qtRakNet
chatServer.depends += consoleThread
