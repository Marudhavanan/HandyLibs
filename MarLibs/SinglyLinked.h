#pragma once
#include "List.h"

typedef struct SL 
{
	int x;
	struct SL* next;
}SL;
class SinglyLinked
{
public:
	SinglyLinked(string name) 
	{
		head = NULL;
		this->name = name;
		count = 0;
	}

	~SinglyLinked();

	void Insert(int x);
	bool DeleteAtPosition(int pos);
	bool Search(int x);
	void print(bool flag = false);
	void reverse();

	int FindMid();

private:
	void print_reverse(SL*);

private:
	SL* head;
	string name;
	int count;
};

