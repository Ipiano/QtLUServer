#ifndef LUAUTHSERVERHANDLER_H
#define LUAUTHSERVERHANDLER_H

#include "rakmessagehandler.h"

class LUAuthServerHandler : public RakMessageHandler
{
    Q_OBJECT

    unsigned int _world;
    unsigned int _char;

public:
    QString serverName(){return "AUTH";}
    LUAuthServerHandler(unsigned int worldPort, unsigned int charPort, QObject* parent=nullptr);

public slots:
    virtual void receiveRAKMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data);
    virtual void receiveLUMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray& data);
};

#endif // LUAUTHSERVERHANDLER_H
