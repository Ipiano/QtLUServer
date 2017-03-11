#ifndef DATABROKER_H
#define DATABROKER_H

#include <QObject>
#include <QtGlobal>
#include <QTextStream>
#include <QHostAddress>
#include "useraccounts.h"

#define DATABROKER DataBroker::sharedInstance()

class DataBroker : public QObject
{
    Q_OBJECT

protected:
    QTextStream* _logger;

public:
    //Allows the application to set up a global data broker object
    //That can be accessed from anywhere
    static DataBroker* _sharedInst;
    static DataBroker* sharedInstance()
    {
        return _sharedInst;
    }

    static void setSharedInstance(DataBroker* db)
    {
        _sharedInst = db;
    }

    DataBroker(QObject* parent = nullptr);
    void setLogger(QTextStream* log)
    {
        _logger = log;
    }

    QString authServerIp(){return QHostAddress(QHostAddress::LocalHost).toString();}
    quint16 authServerPort(){return 1001;}
    QString authServerName(){return "AUTH";}

    QString chatServerIp(){return QHostAddress(QHostAddress::LocalHost).toString();}
    virtual quint16 chatServerPort() = 0;

    QString worldServerIp(){return QHostAddress(QHostAddress::LocalHost).toString();}
    virtual quint16 worldServerPort() = 0;

    virtual quint64 getAccountID(QString username) = 0;
    virtual bool checkPassword(quint64 id, QString password) = 0;
    virtual accountInfo getAccountInfo(quint64 id) = 0;
    virtual void setAccountInfo(quint64 id, accountInfo info) = 0;
};

#endif // DATABROKER_H
