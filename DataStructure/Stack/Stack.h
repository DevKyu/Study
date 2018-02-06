#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct PrevNode
{
	PrevNode* prev;
	int data;
};

class Stack
{
private:
	int* stack;
	int top;
	int capa;
public:
	Stack(int capacity);
	~Stack();
	void Push(int data);
	int Pop();
	int Top();
	int Size();
	bool Empty();
};

class StackList
{
private:
	Node* head;
	Node* top;
public:
	StackList();
	~StackList();
	void Push(int data);
	int Pop();
	int Top();
	int Size();
	bool Empty();
};

class PrevStackList
{
private:
	PrevNode* head;
	PrevNode* top;
public:
	PrevStackList();
	~PrevStackList();
	void Push(int data);
	int Pop();
	int Top();
	int Size();
	bool Empty();
};