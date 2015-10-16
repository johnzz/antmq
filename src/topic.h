#ifndef __TOPIC_H
#define __TOPIC_H


struct antmqTopic  {
	char *name;
	unsigned long rate;//bytes/second

	
	int partions;
	struct antmqPartions **partions;

	int 2pc_flag;
	int consumers;
	int producers;
	
}
#endif
