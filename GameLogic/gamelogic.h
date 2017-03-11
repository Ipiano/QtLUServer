#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <QTextStream>

#include "useraccounts.h"

#define GAMELOGIC GameLogic::sharedInstance()

class GameLogic : public QObject
{
    Q_OBJECT

    static GameLogic* _instance;
    QTextStream* _logger = nullptr;

public:
    explicit GameLogic(QObject *parent = 0);

    void setLogger(QTextStream* log)
    {
        _logger = log;
    }

    static GameLogic* sharedInstance()
    {
        if(!_instance)
            _instance = new GameLogic();
        return _instance;
    }

    ACCOUNTSTATUS attemptLogin(QString username, QString password);

};

#endif // GAMELOGIC_H
