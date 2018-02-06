#include "Queue.h"

/* Linear Array Queue*/
Queue::Queue(int capacity) : queue(0), front(0), rear(0), cap(capacity)
{
	queue = new int[capacity]();
}

Queue::~Queue()
{
	delete[] queue;
	queue = NULL;
}

void Queue::EnQueue(int data)
{
	if (rear < cap)
		queue[rear++] = data;
	else
		cout << "Queue is Full!!" << endl;
}

int Queue::DeQueue()
{
	return front < rear ? queue[front++] : -1;
}

int Queue::Size()
{
	return rear - front;
}

bool Queue::Empty()
{
	return front == rear;
}


/* Circular Array Queue*/
CircularQueue::CircularQueue(int capacity) : queue(0), front(0), rear(0), cap(capacity+1)
{
	queue = new int[capacity + 1]();
}

CircularQueue::~CircularQueue()
{
	delete[] queue;
	queue = NULL;
}

void CircularQueue::EnQueue(int data)
{
	if ((rear+1) % cap != front % cap)
		queue[rear++%cap] = data;
	else
		cout << "Queue is Full!!" << endl;
}

int CircularQueue::DeQueue()
{
	return front < rear ? queue[front++%cap]: -1;
}

int CircularQueue::Size()
{
	return rear - front;
}

bool CircularQueue::Empty()
{
	return front == rear;
}


/* Linked Queue*/
LinkedQueue::LinkedQueue()
{
	front = rear = NULL;
}

LinkedQueue::~LinkedQueue()
{
	delete front;
	front = rear = NULL;
}

void LinkedQueue::EnQueue(int data)
{
	if (front != NULL)
	{
		rear->next = new Node();
		rear = rear->next;
		rear->data = data;
	}
	else
	{
		rear = new Node();
		front = rear;
		rear->data = data;
	}
}

int LinkedQueue::DeQueue()
{
	if (front != NULL)
	{
		int data = 0;

		if (front != rear)
		{
			Node* temp = front;
			data = front->data;
			front = front->next;

			delete temp;
		}
		else
		{
			data = front->data;

			delete front;
			front = rear = NULL;
		}

		return data;
	}
	else
		return -1;
}

int LinkedQueue::Size()
{
	int size = 0;

	if (front != NULL)
	{
		Node* temp = front;
		while (temp != NULL)
			temp = temp->next, size++;
	}

	return size;
}

bool LinkedQueue::Empty()
{
	return front == NULL;
}
