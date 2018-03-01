#pragma once
#include <iostream>
#include <string>
using namespace std;
enum SLOT_STATUS { EMPTY, USE, DELETE };

struct Data
{
	int key;
	string value;
	SLOT_STATUS status; // Chaining X
};

struct Node
{
	Data data;
	Node* next;
};

struct Chain
{
	Node* link;
};

class HashTable
{
private:
	Data* table;
	Chain* ChainTable;
	int capacity;
public:
	HashTable(int = 101);
	~HashTable();
	int LowPrimeNumber(int num);

	/* Linear Probing */
	int Hash(int key);
	void Insert(int key, string value);
	bool Delete(int key, string value);
	bool Search(int key, string value);

	/* Double Hashing */
	int Hash_double(int key);
	void Insert_double(int key, string value);
	bool Delete_double(int key, string value);
	bool Search_double(int key, string value);

	/* Chaining */
	void Insert_chaining(int key, string value);
	bool Delete_chaining(int key, string value);
	bool Search_chaining(int key, string value);
};