#include "log.h"

#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdarg.h>

static FILE *out_file = nullptr;

void log_set_file(FILE *out)
{
	out_file = out;
}

void log_message(const char *lvl, const char *sfp, const char *sf, int l , const char *fmt, ...)
{
	assert(out_file != nullptr);

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
