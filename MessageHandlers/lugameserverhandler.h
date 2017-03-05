#ifndef LUGAMESERVERHANDLER_H
#define LUGAMESERVERHANDLER_H

#include "rakmessagehandler.h"

class LUGameServerHandler : public RakMessageHandler
{
    Q_OBJECT

public:
    LUGameServerHandler(QObject* parent=nullptr);
    QString serverName(){return "GAME";}

public slots:
    virtual void receiveRAKMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data);
    virtual void receiveLUMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data);
};

#endif // LUGAMESERVERHANDLER_H
