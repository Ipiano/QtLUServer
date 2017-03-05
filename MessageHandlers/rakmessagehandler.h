#ifndef RAKMESSAGEHANDLER_H
#define RAKMESSAGEHANDLER_H

#include <QObject>
#include <QDebug>
#include <QtEndian>
#include <functional>
#include <QMap>

#include "RakNetTypes.h"
#include "logger.h"

#define HEADERHANDLER(funcName)void funcName(SystemIndex& sysInd, SystemAddress& sysAddr, QByteArray& data)
typedef std::function<void(SystemIndex&, SystemAddress&, QByteArray&)> HeaderHandler;
class RakMessageHandler : public QObject
{
    Q_OBJECT

    QMap<unsigned int, HeaderHandler> _LUHandlers;
    QMap<unsigned int, HeaderHandler> _RakHandlers;

public:
    virtual QString serverName(){return "Server";}
    explicit RakMessageHandler(QObject *parent = nullptr);

protected:
    template<class T, class F>
    void setLUHeaderHandler(unsigned int header, F func, T* ptr)
    {
        using namespace std::placeholders;
        setLUHeaderHandler(header, std::bind(func, ptr, _1, _2, _3));
    }

    template<class T, class F>
    void setRakHeaderHandler(unsigned int header, F func, T* ptr)
    {
        using namespace std::placeholders;
        setRakHeaderHandler(header, std::bind(func, ptr, _1, _2, _3));
    }

    void setLUHeaderHandler(unsigned int header, HeaderHandler handler)
    {
        _LUHandlers[header] = handler;
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
        if( header == 83 )
        {
            QByteArray LUHeader = data.left(4);
            unsigned int LUHeaderPack = (LUHeader[0]<<24)|(LUHeader[1]<<16)|(LUHeader[2]<<8)|(LUHeader[3]);

            DEBUG("Converting LU Header " << LUHeader.toHex() << " -> " << LUHeaderPack);
            INFO("CLIENT " << sysAddr.ToString() << " -> " << serverName() << " : " << header);
            DEBUG(data.toHex());

            auto handler = _LUHandlers.find(LUHeaderPack);
            if(handler != _LUHandlers.end())
                (*handler)(sysInd, sysAddr, data);
        }
        else
        {
            auto handler = _RakHandlers.find(header);
            if(handler != _RakHandlers.end())
                (*handler)(sysInd, sysAddr, data);
        }
    }

signals:
    void sendMessage(QByteArray, SystemAddress);
};

#endif // RAKMESSAGEHANDLER_H
