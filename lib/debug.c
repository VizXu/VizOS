#include <stdarg.h>

#include <viz/kernel.h>

extern int vsprintf(char * buf, const char * fmt, va_list args);

static char log_buf[1024];                       

static unsigned short cur_log_level = LOG_INFO_TYPE;

// linux0.12 kernel log function
void Log(unsigned short log_level, const char *fmt, ...)
{
    if (log_level >= cur_log_level) {
        va_list args;                           

        va_start(args, fmt);
        vsprintf(log_buf, fmt, args);
        va_end(args);
        console_print(log_buf);            
    }
}
