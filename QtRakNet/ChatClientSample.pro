TEMPLATE = subdirs

SUBDIRS = \
    qtRakNet \
    chatClient \
    consoleThread

#PWD Breaks on my win10 if you have spaces in your path (which I do)
#But I have a symbolic link set up which has the same path, just with _ instead of the space
#I should probably just change my user to not have a space...
TMPPWD = $$replace(PWD," ","_")

chatClient.file = $$TMPPWD/ChatClientSample/QtRakChatClient.pro
qtRakNet.file = $$TMPPWD/QtRakNet.pro
consoleThread.file = $$TMPPWD/ConsoleThread/ConsoleThread.pro

chatClient.depends = qtRakNet
chatClient.depends += consoleThread
