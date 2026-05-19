#include "log.h"

#include <stdio.h>
#include <time.h>
#include <stdarg.h>

#define DEFAULT_OUT_FILE stdout

static FILE *out_file = nullptr;

void log_set_output(FILE *out)
{
	out_file = out;
}

void log_message(const char *lvl, const char *sfp, const char *sf, int l , const char *fmt, ...)
{
	if (out_file == nullptr)
		log_set_output(DEFAULT_OUT_FILE);


	time_t now = time(NULL);
	struct tm tm_buf;
	localtime_r(&now, &tm_buf);

	char timestamp[20];
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &tm_buf);

	fprintf(out_file, "%s [%s] %s:%s:%d ", timestamp, lvl, sfp, sf, l);

	va_list args;
	va_start(args, fmt);
	vfprintf(out_file, fmt, args);
	va_end(args);

	fputc('\n', out_file);
	fflush(out_file);
}
