#include "log.h"
#include <stdarg.h>
#include <time.h>
#include <syslog.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void antmqLogRaw(int level, const char *msg) {
	const int syslogLevelMap[] = { LOG_DEBUG, LOG_INFO, LOG_NOTICE, LOG_WARNING };
	const char c[ANTMQ_LOG_TYPE];
	FILE *fp;
	char time_buf[64];
	char buf[ANTMQ_MAX_LOG_LEN];
	int ret = 0;
	int rawmode = (level & ANTMQ_LOG_RAW);
	int log_to_stdout = server.logfile[0] == '\0';
	
	level &= 0xff; /* clear flags */
	if (level < server.logLevel) {
		return;
	}
	
	fp = log_to_stdout ? stdout : fopen(server.logfile,"a");
	if (!fp) {
		return;
	}
	
	if (rawmode) {
		fprintf(fp,"%s",msg);
	} else {
		int off;
		struct timeval tv;
		pid_t pid = getpid();
	
		gettimeofday(&tv,NULL);
		off = strftime(time_buf,sizeof(time_buf),"%d %b %H:%M:%S.",localtime(&tv.tv_sec));
		snprintf(time_buf+off,sizeof(time_buf)-off,"%03d",(int)tv.tv_usec/1000);

		ret = snprintf(buf,sizeof(buf),"%d:%c %s %c %s\n",(int)getpid(), buf,c[level],msg);
		if (ret == 0) {
			fprintf(fp,"%s %s snprintf error!",__FILE__,__LINE__);
		}

		fwrite(buf, ret, 1,fp);
	}
	fflush(fp);
	
	if (!log_to_stdout) {
		fclose(fp);
	}
	
	if (server.syslog_enabled) {
		syslog(syslogLevelMap[level], "%s", msg);
	}
	
}
void antmqLog(int level, const char *fmt, ...) {
	va_list ap;
	char msg[ANTMQ_MAX_LOGMSG_LEN];

	if ((level&0xff) < server.logLevel){
		return ;
	}
	
	va_start(ap, fmt);
	vsnprint(msg, sizeof(msg), fmt, ap);
	va_end(ap);

	antmqLogRaw(level,msg);
		
}

