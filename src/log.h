#pragma once

#include <stdio.h>
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 3

// set the default log level to DEBUG if -DLOG_MIN_LEVEL is not used
#ifndef LOG_MIN_LEVEL
#define LOG_MIN_LEVEL LOG_LEVEL_DEBUG
#endif

/* log_message isn't used directly, but is used by the macros defined below */
void log_message(int log_level, const char *file, const char *func, int line,
		 const char *fmt, ...) __attribute__((format(printf, 5, 6)));

void log_set_output(FILE *out);

// Debug Macro
#if LOG_MIN_LEVEL <= LOG_LEVEL_DEBUG
#define LOG_DEBUG(fmt, ...) \
	log_message(LOG_LEVEL_DEBUG, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...) ((void)0)
#endif

// Info Macro
#if LOG_MIN_LEVEL <= LOG_LEVEL_INFO
#define LOG_INFO(fmt, ...) \
	log_message(LOG_LEVEL_INFO, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#else
#define LOG_INFO(fmt, ...) ((void)0)
#endif

#if LOG_MIN_LEVEL <= LOG_LEVEL_WARN
#define LOG_WARN(fmt, ...) \
	log_message(LOG_LEVEL_WARN, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#else
#define LOG_INFO(fmt, ...) ((void)0)
#endif

// Error messages are always shown
#define LOG_ERROR(fmt, ...) \
	log_message(LOG_LEVEL_ERROR, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
