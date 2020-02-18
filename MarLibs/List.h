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

	
	virtual void Insert(int x) = 0;
	virtual bool Search(int x) = 0;
	virtual void reverse() = 0;
	virtual void print(bool flag) = 0;
	virtual int  FindMid() = 0;
	virtual bool DeleteAtPosition(int pos) = 0;
	virtual bool TieLoop(int pos1, int pos2) = 0;
	virtual bool IsLoop(void) = 0;
	virtual void Untie(void) = 0;

private:
	string myName;

};

