#include "lugameserverhandler.h"
#include "MessageIdentifiers.h"

#include <QDebug>

LUGameServerHandler::LUGameServerHandler(QObject *parent) : RakMessageHandler(parent)
{

}

void LUGameServerHandler::receiveRAKMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data)
{

}

void LUGameServerHandler::receiveLUMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data)
{

}
