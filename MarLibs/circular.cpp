#include "circular.h"

bool circular::push(int element)
{
	//check for queue full
	if (move_ptr(cq.head) == cq.tail - 1)
	{
		cout << "Circular queue full!" << endl;
		return false;
	}
	cq.data[cq.head] = element;
	cq.head = move_ptr(cq.head);

	return true;
}

bool circular::pop(int & element)
{
	//check for empty
	if (cq.head == cq.tail)
	{
		cout << "Circular Queue empty!" << endl;
		return false;
	}
	element = cq.data[cq.tail];
	cq.tail = move_ptr(cq.tail);
	return true;
}



int circular::move_ptr(int x)
{
	if (x >= cq.count)
		return 0;
	return x+1;
}
