#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
	Head = Tail = NULL;
}

DoubleLinkedList::~DoubleLinkedList()
{
	delete Head;
	Head = Tail = NULL;
}

void DoubleLinkedList::InsertNode(int data)
{
	if (Tail != NULL)
	{
		Node* prev = Tail;
		Tail->next = new Node();

		Tail = Tail->next;
		Tail->prev = prev;
		Tail->data = data;
	}
	else
	{
		Head = new Node();
		Tail = Head;
		Tail->data = data;
	}
}

void DoubleLinkedList::DeleteNode()
{
	if (Head != Tail)
	{
		if (Tail->next == NULL)
		{
			Tail = Tail->prev;

			delete Tail->next;
			Tail->next = NULL;
		}
		else if (Tail->next != NULL)
		{
			Node* temp = Tail;

			Tail->prev->next = Tail->next;
			Tail->next->prev = Tail->prev;
			Tail = Tail->prev;

			delete temp;
		}
	}
	else
	{
		delete Head;
		Head = Tail = NULL;
	}
}

bool DoubleLinkedList::FindData(int data)
{
	if (Head != NULL)
	{
		Node* temp = Head;
	
		while (temp != NULL)
		{
			if (temp->data != data)
				temp = temp->next;
			else
			{
				Tail = temp; 
				return true;
			}
		}
	}

	return false;
}

int DoubleLinkedList::CurrentData()
{
	return Tail != NULL ? Tail->data : -1;
}

int DoubleLinkedList::Size()
{
	int size = 0;

	if (Head != NULL)
	{
		Node* temp = Head;
		while (temp != NULL)
			temp = temp->next, size++;
	}

	return size;
}

bool DoubleLinkedList::Empty()
{
	return Head == NULL ? true : false;
}
