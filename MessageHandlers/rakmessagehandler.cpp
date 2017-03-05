#include "rakmessagehandler.h"
#include "logger.h"
#include "messageheaders.h"

RakMessageHandler::RakMessageHandler(QObject *parent) : QObject(parent)
{
    connect(this, &RakMessageHandler::sendMessage,
    [this](QByteArray data, SystemAddress addr)
    {
        INFO(serverName() << " -> CLIENT " << addr.ToString());
        DEBUG(data.toHex());
    });

    setLUHeaderHandler(HEADERS::ALL::VERSION_CONFIRM, &RakMessageHandler::VERSION_CONFIRM, this);
}

HEADERHANDLER(RakMessageHandler::VERSION_CONFIRM)
{
    INFO("Got handshake");
}
