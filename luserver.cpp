#include "luserver.h"

LUServer::LUServer(QString pass, RakMessageHandler* handler, QObject *parent) : QObject(parent)
{
    handler->setParent(this);
    _handler = handler;

    _peer = new QtRakPeer(30, this);
    _peer->SetIncomingPassword(pass.toLatin1().data(), pass.length());

    connect(_peer, &QtRakPeer::Recieve, _handler, &RakMessageHandler::handleMessage);
    connect(_handler, &RakMessageHandler::sendMessage,
    [this](QByteArray data, SystemAddress address)
    {
        _peer->Send(data, SYSTEM_PRIORITY, RELIABLE_ORDERED, 0, address, true);
    });
}

LUServer::~LUServer()
{
    shutdown(300);
}

bool LUServer::startup(unsigned int port, int maxConnections, int maxIncoming)
{
    SocketDescriptor sd(port, 0);

    bool good = _peer->Startup(maxConnections, 30, &sd, 1);
    _peer->SetMaximumIncomingConnections(maxIncoming);

    if(good)
        qInfo() << "Server started at " << _peer->GetLocalIP(0) << ":" << port;

    return good;
}

void LUServer::shutdown(unsigned int block)
{
    _peer->Shutdown(block);
}

bool LUServer::active()
{
    return _peer->IsActive();
}
