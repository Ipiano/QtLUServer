#ifndef LOGGER_H
#define LOGGER_H

#include <QTextStream>

enum class LOG_LEVEL{TRACE, DEBUG, INFO, WARN, ERROR};
extern QTextStream* LOG_STREAM;
extern LOG_LEVEL CURRENT_LOG_LEVEL;

#define LOG(data, level)if(LOG_STREAM && CURRENT_LOG_LEVEL <= level){(*LOG_STREAM) << data << endl;}
#define TRACE(data) LOG(data, LOG_LEVEL::TRACE)
#define DEBUG(data) LOG(data, LOG_LEVEL::DEBUG)
#define INFO(data) LOG(data, LOG_LEVEL::INFO)
#define WARN(data) LOG(data, LOG_LEVEL::WARN)
#define ERROR(data) LOG(data, LOG_LEVEL::ERROR)

#endif // LOGGER_H
