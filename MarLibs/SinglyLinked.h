#pragma once
#include "List.h"

typedef struct SL 
{
	int x;
	struct SL* next;
}SL;
class SinglyLinked : public List
{
public:
	SinglyLinked(string name) : List(name)
	{
		head = NULL;
		this->name = name;
		count = 0;
		looped = false;
	}

	~SinglyLinked();

	virtual void Insert(int x);
	virtual bool DeleteAtPosition(int pos);
	virtual bool Search(int x);
	virtual void print(bool flag = false);
	virtual void reverse();

	virtual int FindMid();
	virtual bool TieLoop(int pos1, int pos2);
	virtual bool IsLoop();
	virtual void Untie();

private:
	void print_reverse(SL*);

private:
	SL* head;
	SL* saved, *saved_next;
	string name;
	
};

