#pragma once
#include <iostream>
#include <string>

using namespace std;
//Base class for Single, double lists.

class List
{
public:

	List(string name)
	{
		myName = name;
	}

	virtual ~List()
	{
		cout << myName << " Destructed" << endl;
	}

	virtual string GetName() { return myName; }
	virtual void Insert(int x) = 0;
	virtual bool Search(int x) { cout << __FUNCTION__ << " Not implemented!"; return false; }

	virtual void reverse() { cout << __FUNCTION__ << " Not implemented!"; };
	virtual void print(bool flag) { cout << __FUNCTION__ << " Not implemented!"; };
	virtual int  FindMid() { cout << __FUNCTION__ << " Not implemented!"; return 0; };
	virtual bool DeleteAtPosition(int pos) { cout << __FUNCTION__ << " Not implemented!"; return false; };
	virtual bool TieLoop(int pos1, int pos2) { cout << __FUNCTION__ << " Not implemented!"; return false; };
	virtual bool IsLoop(void) { cout << __FUNCTION__ << " Not implemented!"; return false; };
	virtual void Untie(void) { cout << __FUNCTION__ << " Not implemented!";  };

protected:
	string myName;
	int count;
	bool looped;
};

