#ifndef FILEBROKER_H
#define FILEBROKER_H

#include "databroker.h"

class FileBroker : public DataBroker
{
    Q_OBJECT

public:
    FileBroker(QObject* parent = nullptr);

    virtual quint16 chatServerPort();
    virtual quint16 worldServerPort();

    virtual quint64 getAccountID(QString username);
    virtual bool checkPassword(quint64 id, QString password);
    virtual accountInfo getAccountInfo(quint64 id);
    virtual void setAccountInfo(quint64 id, accountInfo info);
};

#endif // FILEBROKER_H
