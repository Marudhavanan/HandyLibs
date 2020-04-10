// MarLibs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "SinglyLinked.h"
#include "DoubleLinked.h"
#include "circular.h"
#include "HashTable.h"

void test_lists()
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
	int count = 20;
	//Basic test
	cq->create(count);
	for (int i = 0; i < count; i++)
	{
		cq->push(i);
	}
	int ele = 0;

	cq->dump();

	//Overflow test
	for (int i = 0; i < count; i++)
	{
		cq->push(i);
	}
	cq->push(11);

	//Push pop
	cq->destroy();
	cq->push(1);
	cq->push(2);
	cq->pop(ele);
	cq->dump();

}
const char *plst[] =
{
"BASEADR:1000",
"DMA : CPU",
"MBAR : 0",
"STRTOFF : 1000",
"TSTMODE : NORMAL",
"LEN : 7FF000",
"AdvDgn : DISABLED",
"LOOPS : 1",
"BUSWIDTH : 32",
"LPERR : DISABLED",
"CHIPWIDTH : 16",
"ROWCOL4 : XXXXXXXX",
"ROWCOL3 : BBRRRRRR",
"ROWCOL2 : RRRRRRCC",
"ROWCOL1 : CCCCCCXX",
"CHIPLIST :",
"DBUSTST:ENABLED",
"CHPSEL : ENABLED",
"ADDRTST : ENABLED",
"MEMSZVFY : ENA",
"STATPTST : ENABLED",
"INVRTTST : ENABLED",
"ROLL1BIT : DISABLED",
"INCRTST : ENABLED",
"RANDTST : ENABLED",
"HOSTREP : YES",
"RSEED : 0",
"REFRSHTST : ENABLED",
"REFRSHWAIT : 4000",
"RANDACCTST : ENABLED",
"RANDACCCNT : 1000000",
"CUSTST : DISABLED",
"CPATTW : 64bit",
"CUSALG : STATIC",
"BURSTCNT : 100",
"CUSFILL : DISABLED",
"CUSCHCK : DISABLED",
"SEED3 : 3",
"SEED2 : 2",
"SEED1 : 1",
"INCRSEED : 100",
"SEED7 : 7",
"SEED6 : 6",
"SEED5 : 5",
"SEED4 : 4",
"SEEDFILE : seedfile.txt",
"TST1MBTO : 1000",
"SYSDATE : 04 / 08 / 2020",
"HOSTLOOP:0",
"EXTLOOP : 0",
"TESTMODE : 4",
"BRDNUM : 1",
""
};
int main()
{
	//create
	HashTable ht(1231);
	//Prepare local data
	ht_item plist[1024];
	memset(plist, 0, sizeof(plist));
	int i = 0;
	while (strlen(plst[i]))
	{
		//split and extract key/val to local
		char *key = plist[i].key;
		char *val = plist[i].value;
		int j = 0, k = 0;
		while (plst[i][j] != ':')
			key[j] = plst[i][j++];
		key[j++] = '\0';
		while (plst[i][j] != '\0')
			val[k++] = plst[i][j++];
		val[k] = '\0';
		//insert to hash table
		plist[i].next = NULL;
		ht.insert(&plist[i]);
		i++;
	}

	//lookup
	i = 0;
	while (strlen(plist[i].key))
	{
		char *val;
		if (!ht.lookup(plist[i].key, &val))
		{
			cout << plist[i].key << " Not found!" << endl;
		}
		cout << plist[i].key << ":" << val << endl;
		i++;
	}

	
	
    return 0;
}
