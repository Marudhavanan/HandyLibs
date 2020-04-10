#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
typedef struct s_ht_item
{
	char key[64];
	char value[64];
	s_ht_item *next;
}ht_item;

typedef struct
{
	int size;
	int count;
	ht_item **slot;
}hash_table;

class HashTable
{

public:
	HashTable(int size) 
	{
		ht.count = 0;
		ht.size = size; 
		ht.slot = (ht_item **)calloc(ht.size * sizeof(ht_item*),1);
	}
	
	~HashTable() 
	{
		if (ht.slot)
			free(ht.slot);
	}

	bool insert(ht_item *item);
	bool lookup(char *key, char **val);
	unsigned int hash(const char *key);

private:
	hash_table ht;
};

