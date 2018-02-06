#include "Stack.h"

#define CreateNode new Node()
#define CreatePrevNode new PrevNode()

/* Array Stack */
Stack::Stack(int capacity=10) : stack(0), top(0), capa(capacity)
{
	try
	{
		stack = new int[capacity]();
	}
	catch (exception& e)
	{
		delete[] stack;
		throw e;
	}
}

Stack::~Stack()
{
	try
	{
		delete[] stack;
		stack = NULL;
	}
	catch (...)
	{
		cout << "Delete Error!" << endl;
		return;
	}
}

void Stack::Push(int data)
{
	if (top < capa)
		stack[top++] = data;
	else
		cout << "Stack is Full !!" << endl;
}

int Stack::Pop()
{
	return top > 0 ? stack[--top] : -1;
}

int Stack::Top()
{
	return top > 0 ? stack[top-1] : -1;
}

int Stack::Size()
{
	return top;
}

bool Stack::Empty()
{
	return !(top > 0);
}


/* Single Linked Stack */
StackList::StackList()
{
	head = top = NULL;
}

StackList::~StackList()
{
	int size = Size();

	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			Pop();
			cout << "Destructor Pop!!" << endl;
		}
	}
}

void StackList::Push(int data)
{
	if (top != NULL)
	{
		top->next = CreateNode;
		top = top->next;
		top->data = data;
	}
	else
	{
		head = CreateNode;
		top = head;
		top->data = data;
	}
}

int StackList::Pop()
{
	if (top != NULL)
	{
		int data = top->data;

		if (head != top)
		{
			Node* temp = head;

			while (temp->next != top)
				temp = temp->next;

			top = temp;
			delete top->next;
			top->next = NULL;
			temp = NULL;
		}
		else
		{
			delete top;
			head = top = NULL;
		}

		return data;
	}
	else
		return -1;
}

int StackList::Size()
{
	int size = 0;

	if (top != NULL)
	{
		Node* temp = head;
		while (temp != NULL)
			temp = temp->next, size++;
	}

	return size;
}

int StackList::Top()
{
	return top->data;
}

bool StackList::Empty()
{
	return (top == NULL);
}


/* Single Previous Linked Stack */
PrevStackList::PrevStackList()
{
	head = top = NULL;
}

PrevStackList::~PrevStackList()
{
	int size = Size();

	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			Pop();
			cout << "Destructor Pop!!" << endl;
		}
	}
}

void PrevStackList::Push(int data)
{
	if (top != NULL)
	{
		PrevNode* temp = CreatePrevNode;
		temp->prev = top;
		temp->data = data;
		top = temp;
		temp = NULL;
	}
	else
	{
		head = CreatePrevNode;
		top = head;
		top->data = data;
	}
}

int PrevStackList::Pop()
{
	if (top != NULL)
	{
		int data = top->data;

		if (top->prev != NULL)
		{
			PrevNode* temp = top;
			top = top->prev;

			delete temp;
			temp = NULL;
		}
		else
		{
			delete top;
			head = top = NULL;
		}

		return data;
	}
	else
		return -1;
}

int PrevStackList::Size()
{
	int size = 0;

	if (top != NULL)
	{
		PrevNode* temp = top;
		while (temp != NULL)
			temp = temp->prev, size++;
	}

	return size;
}

int PrevStackList::Top()
{
	return top->data;
}

bool PrevStackList::Empty()
{
	return (top == NULL);
}