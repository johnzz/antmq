#ifndef __NETWORKING_H
#define __NETWORKING_H


#define AN_OK 0
#define AN_ERR -1

#define AN_NONE 0
#define AN_READABLE 1
#define AN_WRITEABLE 2

#define AN_FILE_EVENTS 1
#define AN_TIME_EVENTS 2
#define AN_ALL_EVENTS (AN_FILE_EVENTS|AN_TIME_EVENTS)

#define AN_NOMORE -1

struct antmqEvent {
	int mask;
	antmqProc *readProc;
	antmqProc *writeProc;
	//int fd;
	void *data;
	
};

struct antmqEventloop{

};

typedef void antmqProc(struct antmqEventloop *eventloop, int fd, void *clientdata, int mask);
#endif