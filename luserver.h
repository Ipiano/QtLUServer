#ifndef LUSERVER_H
#define LUSERVER_H

#include <QObject>

#include "MessageHandlers/rakmessagehandler.h"
#include "QtRakPeer.h"

class LUServer : QObject
{
    Q_OBJECT

    QtRakPeer* _peer;
    RakMessageHandler* _handler;
    QTextStream* _logger;

public:
    LUServer(QString pass, RakMessageHandler* handler, QTextStream* logger = nullptr, QObject* parent=nullptr);
    ~LUServer();

    bool startup(unsigned int port, int maxConnections, int maxIncoming);
    void shutdown(unsigned int block);
    bool active();
};

#endif // LUSERVER_H
