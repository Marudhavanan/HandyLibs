// MarLibs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SinglyLinked.h"
#include "DoubleLinked.h"
#include "circular.h"


int main()
{
    //List *l = new SinglyLinked("Singly");
    List* l = new DoubleLinked("Double");
    
    cout << "Name:" << l->GetName() << endl;

    for (int i = 0; i < 32; i++)
        l->Insert(i);

    l->print(false);
    cout << (l->Search(5) ? "Found" : "Not Found") << endl;
    l->reverse();
    l->print(false);

    cout << "Midpoint element:" << l->FindMid() << endl;

    l->DeleteAtPosition(0);
    l->print(false);

    l->TieLoop(12, 2);
    cout << "Is looped:" << (l->IsLoop() ? "Yes" : "No") << endl;
    l->Untie();
    cout << "Is looped:" << (l->IsLoop() ? "Yes" : "No") << endl;
    l->print(false);

    delete l;

	//Circular queue
	queue *cq = new circular("Circular");
	int count = 10;
	cq->create(count);
	for (int i = 0; i < count; i++)
	{
		cq->push(i);
	}
	int ele = 0;
	while(cq->pop(ele))
	{
		cout << "CQ element:" << ele << endl;
	}
	
	
    return 0;
}
