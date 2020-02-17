#include "SinglyLinked.h"

SinglyLinked::~SinglyLinked()
{
	SL* e = head;
	int count = 0;
	while (e)
	{
		SL* t = e;
		e = e->next;
		free(t);
		count++;
	};
	cout << "Deleted " << count << " Elements" << endl;
}

void SinglyLinked::Insert(int x)
{
	//Allocate for element
	SL* elm = (SL*)malloc(sizeof(SL));
	if (!elm) return;
	elm->next = NULL;
	elm->x = x;
	count++;
	//Is first?
	if (head == NULL)
	{
		head = elm;
		return;
	}

	//Insert at head
	elm->next = head;
	head = elm;

}

bool SinglyLinked::Search(int x)
{
	SL* elm = head;
	cout << "Searching for:" << x << endl;
	while (elm)
	{
		if (elm->x == x)
			return true;
		elm = elm->next;
	}

	return false;
}

void SinglyLinked::print(bool flag)
{
	if (flag)
	{
		cout << "Print in reverse" << endl;
		print_reverse(head);
		cout << endl;
		return;
	}

	SL* e = head;
	cout << "Element count:" << count << endl;
	while (e)
	{
		cout << e->x << "->";
		e = e->next;
	};
	cout << "NULL" << endl;
}


void SinglyLinked::reverse()
{
	SL* prev = NULL;
	SL* cur = head;
	
	while (cur)
	{
		SL* t1 = cur->next;
		cur->next = prev;
		prev = cur;
		cur = t1;
	};

	head = prev;

	return;
}

void SinglyLinked::print_reverse(SL* e)
{
	if (e == NULL)
	{
		cout << "NULL";
		return;
	}
	print_reverse(e->next);
	cout << "->" << e->x;
}
