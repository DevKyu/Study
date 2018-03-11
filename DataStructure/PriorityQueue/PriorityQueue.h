#pragma once
#define SWAP(x, y) { int t = x; x = y; y = t; }

class PriorityQueue
{
private:
	int* Heap;
	int CurrentSize;
	int Capacity;
public:
	PriorityQueue(int = 10);
	~PriorityQueue();
	void Enqueue(int data);
	int Dequeue();
};