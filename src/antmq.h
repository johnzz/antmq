/*
 * Copyright (c) 2015-2016, johnzz<zjqjlu at 163 dot com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of Redis nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef __ANTMQ_H
#define __ANTMQ_H

#include "config.h"
#include "zk_antmq.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>
#include <pthread.h>
#include <syslog.h>



/*args*/
#define ANTMQ_VERSION "antMQ_0.1.0"
#define ANTMQ_REPLY_CHUNK_BYTES 16*1024*1024


//errono
#define ANTMQ_OK	0
#define ANTMQ_ERR	-1

/*connection flags*/
#define ANTMQ_PRODUCER
#define ANTMQ_CONSUMER
#define ANTMQ_BROKER
#define ANTMQ_ZOO

struct antmqState{
	size_t	used_memory;
	char *version;
	unsigned long connections;
	unsigned long replic_offset;
	unsigned long replica_max_expire;
	
	int total_topics;
	struct antmqTopic **topic;
	
	int brokers;
	struct antmqBroker **brokers;
	
	int bad_brokers;
	char *bad_brokers;
	
	int partions;
	struct antmqPartions **partion;

	
	unsigned long alive_time;
	int state;
	
	
};

struct antmqBuf{
	char *buf;
	
	u_char *start;
	u_char *end;
	int pos;
	int len;
};

typedef struct antmqBuf antmqbuf_t;

struct antmqConnection {
	antmqbuf_t *buffer;
	int fd;

	void *data;
	int flag;
	long long bytes;
	

/*response buff and pos*/
	char resp_buf[ANTMQ_REPLY_CHUNK_BYTES];
	int bufpos;
};

struct antmqProducer {
	
};

struct antmqConsumer {
};

struct antmqMessage {

};

struct antmqConfig {
};


#endif