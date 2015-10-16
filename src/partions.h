#ifndef __PARTIONS_H
#define __PARTIONS_H

static unsigned long partion_nums;

struct antmqPartions {
	int controller_epoch;
	char *leader_broker_id;

	struct antmqBroker **brokers;
	int version;
	int leader_epoch;
	//list *rplic_list;
	
};

#endif
