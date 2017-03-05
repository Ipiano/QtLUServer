TMPPWD = $$replace(PWD," ","_")

CONFIG(debug, debug|release){
    LIB_DIR=$$TMPPWD/lib/debug
}else{
    LIB_DIR=$$TMPPWD/lib/release
}

INCLUDEPATH += $$TMPPWD $$TMPPWD/RakNet3.25 $$TMPPWD/ConsoleThread
