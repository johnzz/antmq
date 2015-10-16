#ifndef __LOG_H
#define __LOG_H

#include "antmq.h"

#define ANTMQ_MAX_LOGMSG_LEN 4096
#define ANTMQ_MAX_LOG_LEN 10240

#define ANTMQ_DEBUG 0
#define ANTMQ_NOTICE 1
#define ANTMQ_WARNING 2
#define ANTMQ_DEBUG 3
#define ANTMQ_ERROR 4
#define ANTMQ_LOG_RAW (1<<5) /*STDOUT*/
#define ANTMQ_LOG_TYPE 6


void antmqLogRaw(int level, const char *msg);

void antmqLog(int level, const char *fmt, ...);
#endif
