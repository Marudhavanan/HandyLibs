#include "DoubleLinked.h"

void DoubleLinked::Insert(int x)
{
	DL* e = new DL;
	e->next = e->prev = NULL;
	e->x = x;
	if (!head)
	{
		head = e;
		return;
	}

	//insert at head
	e->next = head;
	head->prev = e;
	head = e;
}

void DoubleLinked::print(bool flag)
{
	if (flag)
	{
		print_reverse(head);
		return;
	}
	DL* cur = head;
	while (cur)
	{
		cout << cur->x << "<->";
		cur = cur->next;
	};
	cout << "NULL" << endl;
}

void DoubleLinked::reverse()
{
	DL* cur = head;
	DL* prev = head;
	
	while (cur)
	{
		//swap pointers of next / prev
		DL* t = cur->next;
		cur->next = cur->prev;
		cur->prev = t;
		prev = cur;
		cur = t;
		 
	};

	head = prev;
}

bool DoubleLinked::DeleteAtPosition(int pos)
{
	DL* cur = head;
	if (!cur) return false;

	if (pos == 0)
	{
		//delete at head
		DL* t = head;
		head = head->next;
		if (head)
			head->prev = NULL;
		free(t);
		return true;
	}
	while (cur && pos--)
	{
		cur = cur->next;
	};
	if (cur)
	{
		DL* t = cur;
		cur->prev->next = cur->next;
		free(cur);
		return true;
	}
	return false;
}

bool DoubleLinked::Search(int x)
{
	DL* cur = head;
	while (cur)
	{
		if (x == cur->x)
			return true;
		cur = cur->next;
	};
	return false;
}

int DoubleLinked::FindMid()
{
	if (!head) return 0;
	if (!head->next)
		return head->x;

	DL* slow = head;
	DL* fast = head->next->next;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	};
	return slow->x;
}

void DoubleLinked::print_reverse(DL *e)
{
	if (!e)
	{
		cout << "NULL";
		return;
	}
	print_reverse(e->next);
	cout << "<->" << e->x;
	return;
}
