#include "luauthserverhandler.h"

#include <QDebug>

LUAuthServerHandler::LUAuthServerHandler(unsigned int worldPort, unsigned int charPort, QObject *parent) : RakMessageHandler(parent)
{
    _world = worldPort;
    _char = charPort;
}

void LUAuthServerHandler::receiveRAKMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data)
{

}

void LUAuthServerHandler::receiveLUMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data)
{

}
