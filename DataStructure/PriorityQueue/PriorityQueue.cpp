#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int capa) : Capacity(capa)
{
	Heap = new int[Capacity]();
}

PriorityQueue::~PriorityQueue()
{
	delete[] Heap;
}

void PriorityQueue::Enqueue(int data)
{
	int CurrentPos = CurrentSize;
	int ParentPos = (CurrentPos - 1) / 2;

	if (CurrentSize == Capacity)
		return;

	Heap[CurrentPos] = data;
	while (CurrentPos > 0 && Heap[CurrentPos] < Heap[ParentPos])
	{
		SWAP(Heap[CurrentPos], Heap[ParentPos]);

		CurrentPos = ParentPos;
		ParentPos = (CurrentPos - 1) / 2;
	}
	CurrentSize++;
}

int PriorityQueue::Dequeue()
{
	int CurrentPos = CurrentSize-1;
	int data = Heap[0];
	int LeftChild = 1, RightChild = 2, MinChild = 0;

	SWAP(Heap[0], Heap[CurrentPos]);
	CurrentPos = 0;

	Heap[LeftChild] < Heap[RightChild] ?
		MinChild = LeftChild :
		MinChild = RightChild;

	while ((Heap[LeftChild] || Heap[RightChild]) && Heap[CurrentPos] > Heap[MinChild])
	{
		SWAP(Heap[CurrentPos], Heap[MinChild]);

		CurrentPos = MinChild;
		LeftChild = (CurrentPos * 2) + 1;
		RightChild = (CurrentPos * 2) + 2;

		Heap[LeftChild] < Heap[RightChild] ?
			MinChild = LeftChild :
			MinChild = RightChild;
	}

	CurrentSize--;
	return data;
}