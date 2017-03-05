#include "databroker.h"

DataBroker* DataBroker::_sharedInst = nullptr;

DataBroker::DataBroker(QObject *parent) : QObject(parent)
{

}
