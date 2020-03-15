#pragma once
#include "queue.h"

typedef struct
{
	int head;
	int tail;
	int count;
	int *data;
}CQ;
class circular :
	public queue
{
public:
	circular(string n) : queue(n) {}
	~circular() {}

	virtual bool create(int count) 
	{ 
		cq.data = (int *)malloc(count * sizeof(int));
		cq.head = cq.tail = 0;
		cq.count = count;
		return true;
	}
	virtual bool push(int element);
	virtual bool pop(int &element);
private:
	int move_ptr(int);
	CQ cq;
};

