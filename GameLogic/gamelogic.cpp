#include "gamelogic.h"
#include "DataBrokers/databroker.h"
#include "logger.h"

GameLogic* GameLogic::_instance = nullptr;

GameLogic::GameLogic(QObject *parent) : QObject(parent)
{

}

ACCOUNTSTATUS GameLogic::attemptLogin(QString username, QString password)
{
    quint32 accountid = DATABROKER->getAccountID(username);
    if (accountid == 0){
        //If the query returns 0 the query failed, no user was found or SQL injection attempt
        return ACCOUNTSTATUS::INVALID_USER;
    }else{
        //check if the password is correct
        bool passwordCorrect = DATABROKER->checkPassword(accountid, password);
        accountInfo info = DATABROKER->getAccountInfo(accountid);

        if (info.locked || info.banned){
            if (info.banned){
                INFO(_logger, "User " << accountid << " : " << username << " is banned!");
                return ACCOUNTSTATUS::BANNED;
            }
            else{
                INFO(_logger, "User " << accountid << " : " << username << " is locked!");
                return ACCOUNTSTATUS::LOCKED;
            }
        }
        else{
            ACCOUNTSTATUS ret = ACCOUNTSTATUS::SUCCESS;
            if (passwordCorrect){
                //password correct
                info.loginAttempts = 0;
            }
            else{
                //password incorrect
                info.loginAttempts++;
                if (info.loginAttempts > 2){
                    info.locked = true;
                    info.loginAttempts = 3;
                    INFO(_logger, "User " << accountid << " : " << username << " is now locked!");
                    ret = ACCOUNTSTATUS::LOCKED;
                }else{
                    INFO(_logger, "User " << accountid << " : " << username << " has incorrect password!");
                    ret = ACCOUNTSTATUS::INVALID_PASS;
                }
            }
            DATABROKER->setAccountInfo(accountid, info);

            return ret;
        }
    }
}
