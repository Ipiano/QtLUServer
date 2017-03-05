#ifndef FILEBROKER_H
#define FILEBROKER_H

#include "databroker.h"

class FileBroker : public DataBroker
{
    Q_OBJECT

public:
    FileBroker(QObject* parent = nullptr);
};

#endif // FILEBROKER_H
