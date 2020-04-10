#pragma once
#include <iostream>
#include <string>
using namespace std;
class queue
{
public:
	queue(string n) { name = n; }
	virtual ~queue() {}

	virtual bool create(int count) = 0;
	virtual bool push(int element) {
		cout << "push not implemented" << endl;
		return false;
	}
	virtual bool pop(int &element) { cout << "pop not implemented" << endl;  return false; }
	virtual void destroy() {
		cout << "destroy not implemented" << endl;
	}
	virtual void dump() {}
private:
	string name;
};

