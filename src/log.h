#pragma once

#include <stdio.h>
#ifndef NDEBUG
#define LOG_DEBUG(fmt, ...) log_message("DEBUG", __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...) ((void)0);
#endif

#define LOG_ERROR(fmt, ...) log_message("ERROR", __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)

/* log_set_file - Set the log output file */
void log_set_file(FILE *out);

/* log_message - Not intenteded to be used directly, use macros above instead
 * - lvl	= Log Level string. Example: "DEBUG", "ERROR"
 * - sfp	= Source File Path string
 * - sfp	= Source Function string
 * - l		= Source Line integer
 * - fmt	= printf like format string
 * - ...	= prtinf vargs
*/
void log_message(const char *lvl, const char *sfp, const char *sf, int l , const char *fmt, ...);

