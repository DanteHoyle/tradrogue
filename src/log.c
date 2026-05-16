#include "log.h"

#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#define DEFAULT_OUT_FILE stdout

static FILE *out_file = nullptr;

static const char *level_name(int level) {
	switch(level) {
	case LOG_LEVEL_DEBUG:	return "DEBUG";
	case LOG_LEVEL_INFO:	return "INFO";
	case LOG_LEVEL_WARN:	return "WARN";
	case LOG_LEVEL_ERROR:	return "ERROR";
	default:		return "?";
	}
}

void log_set_output(FILE *out)
{
	out_file = out;
}

void log_message(int log_level, const char *file, const char *func, int line
		 , const char *fmt, ...)
{
	if (out_file == nullptr)
		log_set_output(DEFAULT_OUT_FILE);


	time_t now = time(NULL);
	struct tm tm_buf;
	localtime_r(&now, &tm_buf);

	char timestamp[20];
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &tm_buf);

	fprintf(out_file, "%s [%s] %s:%s:%d ",
	        timestamp, level_name(log_level), file, func, line);

	va_list args;
	va_start(args, fmt);
	vfprintf(out_file, fmt, args);
	va_end(args);

	fputc('\n', out_file);
	fflush(out_file);
}
