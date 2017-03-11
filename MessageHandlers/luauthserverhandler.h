#ifndef LUAUTHSERVERHANDLER_H
#define LUAUTHSERVERHANDLER_H

#include "rakmessagehandler.h"
#include "messageheaders.h"
#include "bytestream.h"

#include <QString>

class LUAuthServerHandler : public RakMessageHandler
{
    Q_OBJECT

    HEADERHANDLER(LOGIN_NOTIFY);

    void writeAllExtraData(ByteStream& stream);
    void writeExtraData(quint32 stampId, qint32 bracketNum, quint32 afterNum, ByteStream& stream);

public:
    LUAuthServerHandler(QString serverName, QTextStream *logger=nullptr, QObject* parent=nullptr);

};

#endif // LUAUTHSERVERHANDLER_H
