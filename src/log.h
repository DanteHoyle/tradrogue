#pragma once

#include <stdio.h>

#ifndef NDEBUG
#define LOG_DEBUG(fmt, ...) \
	log_message("DEBUG", __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...) ((void)0);
#endif

#define LOG_ERROR(fmt, ...) \
	log_message("ERROR", __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)

void log_message(const char *lvl, const char *sfp, const char *sf, int l , const char *fmt, ...);
void log_set_output(FILE *out);
