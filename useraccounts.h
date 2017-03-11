#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H

#include <QString>

enum class ACCOUNTSTATUS : unsigned char
{
    SUCCESS = 0x01,
    BANNED,
    PERMISSION_LOW,
    UNKNOWN1,
    UNKNOWN2,
    INVALID_PASS,
    LOCKED,
    INVALID_USER,
    ACTIVATION_PENDING,
    ACCOUNT_DISABLED,
    GAME_TIME_EXPIRED,
    FREE_TRIAL_ENDED,
    PLAY_SCHEDULE_NOT_ALLOWED,
    ACCOUNT_NOT_ACTIVATED
};

struct accountInfo
{
    int loginAttempts = 0;
    bool banned = false;
    bool locked = false;
};

#endif // USERACCOUNTS_H
