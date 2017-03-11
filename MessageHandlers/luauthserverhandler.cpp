#include "luauthserverhandler.h"
#include "bytestream.h"
#include "useraccounts.h"
#include "DataBrokers/databroker.h"
#include "sha512.hh"
#include "messageheaders.h"
#include "MessageIdentifiers.h"
#include "GameLogic/gamelogic.h"

#include <ctime>
#include <QDebug>
#include <QtGlobal>

LUAuthServerHandler::LUAuthServerHandler(QString serverName, QTextStream* logger, QObject *parent) : RakMessageHandler(serverName, logger, parent)
{
    setLUHeaderHandler(HEADERS::CONNECTION_TYPE::AUTH, PACKET_IDS::AUTH::LOGIN_REQUEST, &LUAuthServerHandler::LOGIN_NOTIFY, this);
}

HEADERHANDLER(LUAuthServerHandler::LOGIN_NOTIFY)
{
    DEBUG(_logger, "User login request");

    QString username = data.readWString(33);
    QString password = data.readWString(41);
    INFO(_logger, "Username: " << username);
    INFO(_logger, "Password: " << password);

    quint16 language = data.readNumber<quint16>();
    INFO(_logger, "Language: " << language);

    quint8 uk1 = data.readNumber<quint8>();
    INFO(_logger,"Unknown 1: " << uk1);

    QString proc_info = data.readWString(256);
    QString graph_info = data.readWString(128);
    INFO(_logger, "Proc info: " << proc_info);
    INFO(_logger, "Graphics info: " << graph_info);

    quint32 num_procs = data.readNumber<quint32>();
    quint32 type_procs = data.readNumber<quint32>();
    quint16 lvl_procs = data.readNumber<quint16>();
    quint16 rev_procs = data.readNumber<quint16>();
    INFO(_logger, "Processor: " << num_procs << ", " << type_procs << ", " <<
                    lvl_procs << ", " << rev_procs);

    quint32 uk2 = data.readNumber<quint32>();
    INFO(_logger, "Unknown 2: " << uk2);

    if(data.remaining() > 0)
    {
        quint32 os_major = data.readNumber<quint32>();
        quint32 os_minor = data.readNumber<quint32>();
        quint32 os_build = data.readNumber<quint32>();
        quint32 os_platform = data.readNumber<quint32>();
        INFO(_logger, "OS: " << os_major << "." << os_minor << "."
             << os_build << " -> " << os_platform);
    }

    ByteStream response;
    TRACE(_logger, "Write response header");
    writePacketHeader(ID_USER_PACKET_ENUM, HEADERS::CONNECTION_TYPE::CLIENT, PACKET_IDS::SERVER::LOGIN_RESPONSE, response);

    TRACE(_logger, "Write login attempt");
    ACCOUNTSTATUS loginResult = GAMELOGIC->attemptLogin(username, password);
    response.writeNumber((quint8)loginResult);

    TRACE(_logger, "Write talk like a pirate");
    QString talkLikeAPirate = "Talk_Like_A_Pirate";
    response.writeString(talkLikeAPirate, 33);

    TRACE(_logger, "Write seven blank spots");
    //Write 7 blocks of empty space
    for(int i=0; i<7; i++)
        response.writeString("", 33);

    TRACE(_logger, "Write client version");
    //Write client version number
    response.writeNumber<quint16>(1);
    response.writeNumber<quint16>(10);
    response.writeNumber<quint16>(64);

    TRACE(_logger, "Write client keyhash");
    //Write user key
    time_t t = time(NULL);

    quint32 addr = sysAddr.binaryAddress;
    qint64 a = t * addr;
    std::string keyhash = sw::sha512::calculate(std::to_string(a));
    QString userKey = QString::fromStdString(keyhash);
    response.writeWString(userKey, 33);

    //Write redirect and chat ips
    QString chatIp = DATABROKER->chatServerIp();
    quint16 chatPort = DATABROKER->chatServerPort();

    QString worldIp = DATABROKER->worldServerIp();
    quint16 worldPort = DATABROKER->worldServerPort();

    TRACE(_logger, "Write chat/world IP");
    response.writeString(worldIp, 33);
    response.writeString(chatIp, 33);
    response.writeNumber(worldPort);
    response.writeNumber(chatPort);

    TRACE(_logger, "Write other ip/guid")
    //Write unknown other ip and possible guid
    QString otherIp = "192.168.0.20";
    QString maybeGuid = "00000000-0000-0000-0000-000000000000";

    response.writeString(otherIp, 33);
    response.writeString(maybeGuid, 37);

    //Zero
    response.writeNumber<quint32>(0);

    TRACE(_logger, "Write locale");
    //Locale
    quint8 locChars[3] = {0x55, 0x53, 0x00};
    for(int i=0; i<3; i++)
        response.writeNumber(locChars[i]);

    //Login data
    response.writeNumber<quint8>(1);
    response.writeNumber<quint8>(0);

    //Another 0
    response.writeNumber<quint64>(0);

    //Write err message
    QString errMsg = "";
    switch(loginResult)
    {
        case ACCOUNTSTATUS::LOCKED:
            errMsg = "We're sorry, your account has been locked from too many login attempts";
        break;
        case ACCOUNTSTATUS::BANNED:
            errMsg = "We're sorry, your account has been banned";
        break;
        case ACCOUNTSTATUS::INVALID_USER:
        case ACCOUNTSTATUS::INVALID_PASS:
            errMsg = "We're sorry, those credentials are not in our database";
        break;
    }

    TRACE(_logger, "Write err msg: " << errMsg);
    response.writeNumber<quint16>(errMsg.size());
    response.writeWString(errMsg, errMsg.size());

    TRACE(_logger, "Write extra data");
    writeAllExtraData(response);

    //TODO: Register successful logins locally

    sendMessage(response.data, sysAddr);
}

void LUAuthServerHandler::writeExtraData(quint32 stampId, qint32 bracketNum, quint32 afterNum, ByteStream& stream)
{
    stream.writeNumber(stampId);
    stream.writeNumber(bracketNum);
    stream.writeNumber(afterNum);
    stream.writeNumber<quint32>(0);
}

// Add extra packet data to the server
void LUAuthServerHandler::writeAllExtraData(ByteStream& stream)
{
    stream.writeNumber<quint32>(320);
    writeExtraData(0, 0, 2803442767, stream);
    writeExtraData(7, 37381, 2803442767, stream);
    writeExtraData(8, 6, 2803442767, stream);
    writeExtraData(9, 0, 2803442767, stream);
    writeExtraData(10, 0, 2803442767, stream);
    writeExtraData(11, 1, 2803442767, stream);
    writeExtraData(14, 1, 2803442767, stream);
    writeExtraData(15, 0, 2803442767, stream);
    writeExtraData(17, 1, 2803442767, stream);
    writeExtraData(5, 0, 2803442767, stream);
    writeExtraData(6, 1, 2803442767, stream);
    writeExtraData(20, 1, 2803442767, stream);
    writeExtraData(19, 30854, 2803442767, stream);
    writeExtraData(21, 0, 2803442767, stream);
    writeExtraData(22, 0, 2803442767, stream);
    writeExtraData(23, 4114, 2803442767, stream);
    writeExtraData(27, 4114, 2803442767, stream);
    writeExtraData(28, 1, 2803442767, stream);
    writeExtraData(29, 0, 2803442767, stream);
    writeExtraData(30, 30854, 2803442767, stream);
}

