#include "SinglyLinked.h"

SinglyLinked::~SinglyLinked()
{
	SL* e = head;
	int count = 0;
	if (looped) return; //mem leak
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

bool SinglyLinked::DeleteAtPosition(int pos)
{
	SL* cur = head;
	SL* prev = head;
	int cur_pos = 0;
	//handle head delete
	if (pos == 0)
	{
		head = head->next;
		free(cur);
		return true;
	}
	while (cur)
	{
		if (cur_pos == pos)
		{
			prev->next = cur->next;
			free(cur);
			return true;
		}

		prev = cur;
		cur = cur->next;
		cur_pos++;
	};
	return false;
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

int SinglyLinked::FindMid()
{
	if (!head) return 0;

	SL* slow = head;
	SL* fast = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	};
	return slow->x;
}

bool SinglyLinked::TieLoop(int pos1, int pos2)
{
	SL* from, * to;
	SL* t = head;
	while (t && pos1--)
	{
		t = t->next;
	};
	from = t;
	t = head;
	while (t && pos2--)
	{
		t = t->next;
	};
	to = t;
	//save from
	saved_next = from->next;
	saved = from;
	from->next = t;
	looped = true;
	return true;
}

bool SinglyLinked::IsLoop()
{
	SL* slow = head;
	SL* fast = head->next;
	while (slow && fast && fast->next)
	{
		if (slow == fast)
			return true;
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}

void SinglyLinked::Untie()
{
	if (!looped) return;
	SL* t = head;
	while (t)
	{
		if (t == saved)
		{
			t->next = saved_next;
			looped = false;
			return;
		}
		t = t->next;
	}
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
