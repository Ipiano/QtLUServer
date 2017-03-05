#include "logger.h"

LOG_LEVEL CURRENT_LOG_LEVEL = LOG_LEVEL::INFO;
QTextStream* LOG_STREAM = nullptr;
