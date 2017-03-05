#ifndef DATABROKER_H
#define DATABROKER_H

#include <QObject>

#define DATABROKER DataBroker::sharedInstance();

class DataBroker : public QObject
{
    Q_OBJECT

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


};

#endif // DATABROKER_H
