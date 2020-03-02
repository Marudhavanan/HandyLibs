#pragma once
#include "List.h"

typedef struct DL
{
	struct DL* next;
	struct DL* prev;
	int x;
}DL;
class DoubleLinked :
	public List
{
public:
	DoubleLinked(string name) : List(name)
	{

	}

	~DoubleLinked()
	{
		DL* e = head;
		int count = 0;
		if (looped) return; //mem leak
		while (e)
		{
			DL* t = e;
			e = e->next;
			free(t);
			count++;
		};
		cout << "Deleted " << count << " Elements" << endl;
	}

	virtual void Insert(int x);
	virtual void print(bool flag = false);
	virtual void reverse();

	virtual bool DeleteAtPosition(int pos);
	virtual bool Search(int x);
	virtual int FindMid();
#if 0
	
	virtual bool TieLoop(int pos1, int pos2);
	virtual bool IsLoop();
	virtual void Untie();
#endif
private:
	void print_reverse(DL *e);
private:
	DL* head;
	
};


