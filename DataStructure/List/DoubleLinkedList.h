#pragma once
#include <iostream>
using namespace std;

struct Node
{
	Node* prev;
	int data;
	Node* next;
};

class DoubleLinkedList
{
private:
	Node* Head;
	Node* Tail;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void InsertNode(int data);
	void DeleteNode();
	int CurrentData();
	int Size();
	bool FindData(int data);
	bool Empty();
};