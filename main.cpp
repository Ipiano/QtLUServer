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

constexpr unsigned int AUTH_PORT = 1001;

int main(int argc, char *argv[])
{
    LOG_STREAM = new QTextStream(stdout);
    CURRENT_LOG_LEVEL = LOG_LEVEL::TRACE;

    QCoreApplication app(argc, argv);

    DataBroker::setSharedInstance(new FileBroker(&app));

    unsigned int worldPort = 2000, charPort = 2001;
    LUServer authServer("3.25 ND1", new LUAuthServerHandler(worldPort, charPort), &app);
    LUServer gameServer("3.25 ND1", new LUGameServerHandler(), &app);

    INFO("Starting authentication server...");
    if(!authServer.startup(AUTH_PORT, 10, 3))
    {
        WARN("Unable to start authentication server, exiting...");
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

    return app.exec();
}
