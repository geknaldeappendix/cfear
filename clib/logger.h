#ifndef __CFEAR_CLIB_LOGGER_H_
#define __CFEAR_CLIB_LOGGER_H_

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

enum LOGLEVEL {
    LOGLEVEL_DEBUG,
    LOGLEVEL_INFO,
    LOGLEVEL_WARNING,
    LOGLEVEL_ERROR,
};

void logger_log(enum LOGLEVEL log_level, char* filename, int fileline, char* format, ...);

#define LOG_DEBUG(format, ...) logger_log(LOGLEVEL_DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__);
#define LOG_INFO(format, ...) logger_log(LOGLEVEL_INFO, __FILE__, __LINE__, format, ##__VA_ARGS__);
#define LOG_WARNING(format, ...) logger_log(LOGLEVEL_WARNING, __FILE__, __LINE__, format, ##__VA_ARGS__);
#define LOG_ERROR(format, ...) logger_log(LOGLEVEL_ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__);

#endif // __CFEAR_CLIB_LOGGER_H_
