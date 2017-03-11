#ifndef LOGGER_H
#define LOGGER_H

#include <QTextStream>

enum class LOG_LEVEL{TRACE, DEBUG, INFO, WARN, ERROR};
extern LOG_LEVEL CURRENT_LOG_LEVEL;

#define LOG(textStream, data, level)if(textStream && CURRENT_LOG_LEVEL <= level){(*textStream) << data << endl;}
#define TRACE(textStream, data) LOG(textStream, data, LOG_LEVEL::TRACE)
#define DEBUG(textStream, data) LOG(textStream, data, LOG_LEVEL::DEBUG)
#define INFO(textStream, data) LOG(textStream, data, LOG_LEVEL::INFO)
#define WARN(textStream, data) LOG(textStream, data, LOG_LEVEL::WARN)
#define ERROR(textStream, data) LOG(textStream, data, LOG_LEVEL::ERROR)

#endif // LOGGER_H
