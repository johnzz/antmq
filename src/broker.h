#ifndef __ANTMQ_BROKER_H
#define __ANTMQ_BROKER_H

#include "broker.h"

#define BROKER_MAX_NAMELEN 40

struct antmqBroker {
	long long requests;
	unsigned long startTime;

	char name[BROKER_MAX_NAMELEN];
	struct antmqPartions *partions;
	char *partions;
	int brokerID;
	/*networking*/
	char *host;
	int port;/*9264 for default*/
	int tcp_backlog;
	struct antmqConsumer **consumers;
	struct antmqProducer **producers;
	struct antmqZookeeper *zoo_server;

	/*configuration*/
	int log_level;
	int maxidletime;
	int tcpkeepalive;
	int daemonize;
	
	/*log*/
	char *logfile;
	int logLevel;
	int syslog_enabled;
	
	int version;
	int state;
	int retry_times;
	int timeout;

	char *configfile;
	int shutdown_asap;
	char *pidfile;
	
}
#endif