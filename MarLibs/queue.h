#pragma once
#include <iostream>
#include <string>
using namespace std;
class queue
{
public:
	queue() {}
	virtual ~queue() {}

	virtual bool create(int count) = 0;
	virtual bool push(int element) {
		cout << "push not implemented" << endl;
	}
	virtual bool pop(int &element) { cout << "pop not implemented" << endl; }
	virtual void destroy() {
		cout << "destroy not implemented" << endl;
	}
};

