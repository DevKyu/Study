#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

class Queue
{
private:
	int* queue;
	int front;
	int rear;
	int cap;
public:
	Queue(int capacity=5);
	~Queue();
	void EnQueue(int data);
	int DeQueue();
	int Size();
	bool Empty();
};

class CircularQueue
{
private:
	int* queue;
	int front;
	int rear;
	int cap;
public:
	CircularQueue(int capacity=5);
	~CircularQueue();
	void EnQueue(int data);
	int DeQueue();
	int Size();
	bool Empty();
};

class LinkedQueue
{
private:
	Node* front;
	Node* rear;
public:
	LinkedQueue();
	~LinkedQueue();
	void EnQueue(int data);
	int DeQueue();
	int Size();
	bool Empty();
};