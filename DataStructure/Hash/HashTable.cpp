#include "HashTable.h"

HashTable::HashTable(int cap) : capacity(cap)
{
	/* Defulat */
	table = new Data[cap]();

	/* Chaining */
	ChainTable = new Chain[cap]();
}

HashTable::~HashTable()
{
	/* Defulat */
	delete[] table;
	table = NULL;

	/* Chaining */
	delete[] ChainTable;
	ChainTable = NULL;
}

int HashTable::LowPrimeNumber(int num)
{
	for (int i = num-1; i >= 2; i--)
	{
		int count = 0;
		for (int j = 2; j <= i; j++)
		{
			if (i%j == 0)
				count++;
		}
		if (count == 1)
			return i;
	}
}


/* Linear Probing */
int HashTable::Hash(int key)
{
	return key % capacity;
}

void HashTable::Insert(int key, string value)
{
	int index = Hash(key);

	if (table[index].status == USE)
	{
		while (table[index].status != EMPTY)
			index++;
	}

	table[index].key = key;
	table[index].value = value;
	table[index].status = USE;
}

bool HashTable::Delete(int key, string value)
{
	int index = Hash(key);

	while (table[index].status != EMPTY)
	{
		if (table[index].value != value)
			index++;
		else
		{
			table[index].key = NULL;
			table[index].value = "";
			table[index].status = DELETE;
			return true;
		}
	}
	return false;
}

bool HashTable::Search(int key, string value)
{
	int index = Hash(key);

	while (table[index].status != EMPTY)
	{
		if (table[index].value != value)
			index++;
		else
			return true;
	}
	return false;
}


/* Double Hashing */
int HashTable::Hash_double(int key)
{
	return 1 + (key % LowPrimeNumber(key));
}

void HashTable::Insert_double(int key, string value)
{
	int index = Hash(key);

	if (table[index].status == USE)
	{
		index = Hash_double(key);
		while (table[index].status != EMPTY)
		{
			index += index;
			if (index >= capacity)
				return;
		}
	}

	table[index].key = key;
	table[index].value = value;
	table[index].status = USE;
}

bool HashTable::Delete_double(int key, string value)
{
	int index = Hash(key);
	bool DoubleHashing = false;

	while (table[index].status != EMPTY)
	{
		if (table[index].value != value)
		{
			if (DoubleHashing)
			{
				index += index;
				if (index >= capacity)
					break;
			}
			else
			{
				index = Hash_double(key);
				DoubleHashing = true;
			}
		}
		else
		{
			table[index].key = NULL;
			table[index].value = "";
			table[index].status = DELETE;
			return true;
		}
	}
	return false;
}

bool HashTable::Search_double(int key, string value)
{
	int index = Hash(key);
	bool DoubleHashing = false;

	while (table[index].status != EMPTY)
	{
		if (table[index].value != value)
		{
			if (DoubleHashing)
			{
				index += index;
				if (index >= capacity)
					break;
			}
			else
			{
				index = Hash_double(key);
				DoubleHashing = true;
			}
		}
		else
			return true;
	}
	return false;
}


/* Chaining */
void HashTable::Insert_chaining(int key, string value)
{
	int index = Hash(key);
	Node* node = NULL;

	if (ChainTable[index].link)
	{
		node = new Node();
		node->next = ChainTable[index].link;
		ChainTable[index].link = node;
	}
	else
	{
		ChainTable[index].link = new Node();
		node = ChainTable[index].link;
	}

	node->data.key = key;
	node->data.value = value;
}

bool HashTable::Delete_chaining(int key, string value)
{
	int index = Hash(key);
	Node* node = ChainTable[index].link;

	if (node)
	{
		if (node->data.key == key && node->data.value == value)
		{
			ChainTable[index].link = node->next;
			delete node;
			return true;
		}

		Node* prev = NULL;
		while (node->next != NULL)
		{
			prev = node;
			node = node->next;

			if (node->data.key == key && node->data.value == value)
			{
				prev->next = node->next;
				delete node;
				return true;
			}
		}
	}
	return false;
}

bool HashTable::Search_chaining(int key, string value)
{
	int index = Hash(key);
	Node* node = ChainTable[index].link;
	
	if (node)
	{
		if (node->data.key == key && 
			node->data.value == value)
			return true;

		while (node->next != NULL)
		{
			node = node->next;
			if (node->data.key == key && 
				node->data.value == value)
				return true;
		}
	}
	return false;
}