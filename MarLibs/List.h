#pragma once
#include <iostream>
#include <string>

using namespace std;

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

	
	virtual int Find(int x) = 0;
	virtual int Pop() = 0;
	virtual int Push(int x) = 0;

private:
	string myName;

};

