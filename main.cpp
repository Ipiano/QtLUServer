#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

#include "consolereaderthread.h"
#include "DataBrokers/databroker.h"
#include "DataBrokers/filebroker.h"
#include "MessageHandlers/lugameserverhandler.h"
#include "MessageHandlers/luauthserverhandler.h"
#include "luserver.h"
#include "logger.h"
#include "GameLogic/gamelogic.h"

int main(int argc, char *argv[])
{
    QTextStream* logger = new QTextStream(stdout);
    CURRENT_LOG_LEVEL = LOG_LEVEL::DEBUG;

    QCoreApplication app(argc, argv);

    DataBroker::setSharedInstance(new FileBroker(&app));
    DATABROKER->setLogger(logger);
    GAMELOGIC->setLogger(logger);

    LUServer authServer("3.25 ND1", new LUAuthServerHandler(DATABROKER->authServerName(), logger), logger, &app);
    LUServer gameServer("3.25 ND1", new LUGameServerHandler("GAME", logger), logger, &app);

    INFO(logger, "Starting authentication server...");
    if(!authServer.startup(DATABROKER->authServerPort(), 10, 3))
    {
        WARN(logger, "Unable to start authentication server, exiting...");
        exit(1);
    }

    if(!gameServer.startup(DATABROKER->worldServerPort(), 10, 3))
    {
        WARN(logger, "Unable to start world server, exiting...");
        exit(1);
    }

    ConsoleReader serverIn;
    serverIn.start();
    QObject::connect(&serverIn, &ConsoleReader::gotLine,
    [&app, &authServer, &gameServer, &serverIn](QString line)
    {
        if(line == "quit")
        {
            QTimer::singleShot(1, &app, &QCoreApplication::quit);
            serverIn.stop();
        }
    });

    int out = app.exec();

    authServer.shutdown(1000);
    gameServer.shutdown(1000);

    delete logger;
    delete DATABROKER;
    delete GAMELOGIC;

    return out;
}
