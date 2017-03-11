#include <QCoreApplication>
#include <QHostAddress>

#include "rakmessagehandler.h"
#include "logger.h"
#include "messageheaders.h"
#include "MessageIdentifiers.h"
#include "bytestream.h"
#include "DataBrokers/databroker.h"

RakMessageHandler::RakMessageHandler(QString serverName, QTextStream* logger, QObject *parent) : QObject(parent), _serverName(serverName), _logger(logger)
{
    _LUHandlers.resize((unsigned int)HEADERS::CONNECTION_TYPE::ENUM_MAX);

    connect(this, &RakMessageHandler::sendMessage,
    [this](QByteArray data, SystemAddress addr)
    {
        INFO(_logger, QString(100, '*'));
        INFO(_logger, this->serverName() << " -> CLIENT " << addr.ToString());
        DEBUG(_logger, data.toHex());
        INFO(_logger, QString(100, '*'));
    });

    setLUHeaderHandler(HEADERS::CONNECTION_TYPE::GENERAL, PACKET_IDS::ANY::VERSION_CONFIRM, &RakMessageHandler::VERSION_CONFIRM, this);
}

HEADERHANDLER(RakMessageHandler::VERSION_CONFIRM)
{
    quint32 version, unknown, remoteConnectionType, pid;
    quint16 port;
    quint32 localConnectionType = (quint32)HEADERS::CONNECTION_TYPE::SERVER;
    if (serverName() == DATABROKER->authServerName()) localConnectionType = (quint32)HEADERS::CONNECTION_TYPE::AUTH;

    version = data.readNumber<quint32>();
    unknown = data.readNumber<quint32>();
    remoteConnectionType = data.readNumber<quint32>();
    pid = data.readNumber<quint16>();
    port = data.readNumber<quint32>();

    DEBUG(_logger, "Client handshake request");
    INFO(_logger, "Client version: " << version);
    INFO(_logger, "Unknown: " << unknown);
    INFO(_logger, "Remote Connection: " << remoteConnectionType);
    INFO(_logger, "Remote PID: " << pid);
    INFO(_logger, "Remote Port: " << port);

    QString emptyStr = data.readString(33);

    ByteStream response(59);
    writePacketHeader(ID_USER_PACKET_ENUM, HEADERS::CONNECTION_TYPE::GENERAL, PACKET_IDS::ANY::VERSION_CONFIRM, response);

    quint32 localVersion = 171022UL;
    quint32 localUnknown = 0x93;
    quint32 localPid = QCoreApplication::applicationPid();
    qint16 localUnknown2 = -1;
    QString localIp = QHostAddress(QHostAddress::LocalHost).toString();

    DEBUG(_logger, "Server handshake response");
    INFO(_logger, "Server Version: " << localVersion);
    INFO(_logger, "Server PID: " << localPid);
    INFO(_logger, "Server IP: " << localIp);

    response.writeNumber(localVersion);
    response.writeNumber(localUnknown);
    response.writeNumber(localConnectionType);
    response.writeNumber(localPid);
    response.writeNumber(localUnknown2);
    response.writeString(localIp, 33);

    sendMessage(response.data, sysAddr);
}
