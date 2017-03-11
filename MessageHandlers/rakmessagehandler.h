#ifndef RAKMESSAGEHANDLER_H
#define RAKMESSAGEHANDLER_H

#include <QObject>
#include <QDebug>
#include <QtEndian>
#include <functional>
#include <QMap>
#include <QTextStream>

#include "messageheaders.h"
#include "RakNetTypes.h"
#include "logger.h"
#include "bytestream.h"

#define HEADERHANDLER(funcName)void funcName(SystemIndex& sysInd, SystemAddress& sysAddr, ByteStream& data)
typedef                   std::function<void(SystemIndex&,        SystemAddress&,         ByteStream&)> HeaderHandler;

class RakMessageHandler : public QObject
{
    Q_OBJECT

    QString _serverName;
    QVector<QMap<unsigned int, HeaderHandler>> _LUHandlers;
    QMap<unsigned int, HeaderHandler> _RakHandlers;

public:
    explicit RakMessageHandler(QString serverName, QTextStream *logger = nullptr, QObject *parent = nullptr);

protected:
    QTextStream* _logger;

    QString serverName(){return _serverName;}

    template<class T, class F, class H>
    void setLUHeaderHandler(HEADERS::CONNECTION_TYPE connType, H header, F func, T* ptr)
    {
        using namespace std::placeholders;
        setLUHeaderHandler(connType, header, std::bind(func, ptr, _1, _2, _3));
    }

    template<class T, class F>
    void setRakHeaderHandler(unsigned int header, F func, T* ptr)
    {
        using namespace std::placeholders;
        setRakHeaderHandler(connType, header, std::bind(func, ptr, _1, _2, _3));
    }

    template<class H>
    void setLUHeaderHandler(HEADERS::CONNECTION_TYPE connType, H header, HeaderHandler handler)
    {
        _LUHandlers[(unsigned int)connType][(unsigned int)header] = handler;
    }

    void setRakHeaderHandler(unsigned int header, HeaderHandler handler)
    {
        _RakHandlers[header] = handler;
    }

private slots:
    HEADERHANDLER(VERSION_CONFIRM);

public slots:
    void handleMessage(unsigned int header, SystemIndex sysInd, SystemAddress sysAddr, QByteArray data)
    {
        INFO(_logger, QString(100, '*'));
        INFO(_logger, "CLIENT " << sysAddr.ToString() << " -> " << serverName() << " : " << hex << header << dec);

        ByteStream stream(data);

        if( header == (unsigned int)HEADERS::PACKET_HEADER::LEGO_PACKET )
        {
            stream.skip(1); // Skip header byte
            unsigned int connection = stream.readNumber<quint16>();
            unsigned int packetType = stream.readNumber<quint32>();
            stream.skip(1); // Skip empty byte

            DEBUG(_logger, "LU Header: " << hex << header << " : " << connection << " : " << packetType << dec);
            DEBUG(_logger, stream.data.toHex());
            INFO(_logger, QString(100, '*'));

            if(connection >= (unsigned int)HEADERS::CONNECTION_TYPE::ENUM_MAX)
            {
                ERROR(_logger, "Invalid connection type: " + connection);
                return;
            }

            auto handler = _LUHandlers[connection].find(packetType);
            if(handler != _LUHandlers[connection].end())
                (*handler)(sysInd, sysAddr, stream);
        }
        else
        {
            DEBUG(_logger, stream.data.toHex());
            INFO(_logger, QString(100, '*'));

            auto handler = _RakHandlers.find(header);
            if(handler != _RakHandlers.end())
                (*handler)(sysInd, sysAddr, stream);
        }
    }

signals:
    void sendMessage(QByteArray, SystemAddress);
};

#endif // RAKMESSAGEHANDLER_H
