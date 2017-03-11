#include "filebroker.h"

FileBroker::FileBroker(QObject *parent) : DataBroker(parent)
{

}

quint16 FileBroker::chatServerPort()
{
    return 2003;
}

quint16 FileBroker::worldServerPort()
{
    return 2002;
}

quint64 FileBroker::getAccountID(QString username)
{
    return username == "ipiano"?1:0;
}

bool FileBroker::checkPassword(quint64 id, QString password)
{
    return id==1?true:false;
}

accountInfo FileBroker::getAccountInfo(quint64 id)
{
    accountInfo out;
    return out;
}

void FileBroker::setAccountInfo(quint64 id, accountInfo info)
{

}
