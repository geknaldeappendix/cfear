#include "logger.h"

static int logger_log_level = 0;

char* logger_log_level_text(enum LOGLEVEL log_level) {
    switch (log_level) {
        case LOGLEVEL_DEBUG: return "DEBUG";
        case LOGLEVEL_INFO: return "INFO";
        case LOGLEVEL_WARNING: return "WARNING";
        case LOGLEVEL_ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void logger_log(enum LOGLEVEL log_level, char *filename, int fileline, char *format, ...) {
    if (log_level < logger_log_level) {
        return;
    }

    char* log_level_text = logger_log_level_text(log_level);
    va_list args;
    va_start(args, format);

    fprintf(stdout, "[%s %s.%u] ", log_level_text, filename, fileline);
    vfprintf(stdout, format, args);
    fprintf(stdout, "\n");

    va_end(args);
}
