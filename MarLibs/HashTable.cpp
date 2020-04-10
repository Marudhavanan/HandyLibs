#include "HashTable.h"


bool HashTable::insert(ht_item *kvpair)
{
	//hash
	unsigned int hash_val = hash((const char *)kvpair->key);
	//insert
	if (ht.slot[hash_val]->key)
	{
		cout << "Collision at slot " << hash_val << endl;
		ht_item *p = ht.slot[hash_val];
		while (p->next)
			p = p->next;
		p->next = kvpair;
		cout << "Chain insert Key = " << kvpair->key << " at slot =" << hash_val << endl;
		return true;
	}
	ht.slot[hash_val] = kvpair;
	cout << "Inserted Key = " << kvpair->key << " at slot =" << hash_val << endl;

	return true;
}

bool HashTable::lookup(char * key, char ** val)
{
	//hash
	unsigned int hash_val = hash((const char *)key);
	//lookup
	if(!ht.slot[hash_val])
		return false;
	ht_item *p = ht.slot[hash_val];
	while (p)
	{
		if (strcmp(p->key, key) == 0)
		{
			*val = p->value;
			return true;
		}
		p = p->next;
	};

	return false;
}

unsigned int HashTable::hash(const char * key)
{
	int prime = 53;
	int buckets = ht.size;
	unsigned int hash_val = 0;
	long pow = 1;
	size_t len = strlen(key);
	for (int i = 0; i < len; i++)
	{
		hash_val = (hash_val + (key[i] - 'Z') * pow) % buckets;
		pow *= (pow * prime) % buckets;
	}
	return hash_val;
}
