#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;

template<typename T>
class Queue
{
	T* queue;
	int size;
	int rear;
	int front;
public:
	Queue();
	Queue(int);
	void enQueue(T);
	T deQueue();
	T peek();
	int getSize();
	bool isFull();
	bool isEmpty();
	void reset();
};
#endif


template<typename T>
Queue<T>::Queue()
{
	size = 100;
	queue = new T[size];
	rear = -1;
	front = -1;
}

template<typename T>
Queue<T>::Queue(int s)
{
	size = s;
	queue = new T[size];
	rear = -1;
	front = -1;
}

template<typename T>
int Queue<T>::getSize()
{
	return size;
}

template<typename T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
	{
		cout << "\nQueue is Full!";
		return;
	}
	else
	{
		rear++;
		queue[rear] = val;
	}
	if (front == -1)
		front = 0;
}

template<typename T>
T Queue<T>::deQueue()
{
	T element;
	if (isEmpty())
	{
		cout << "\nQueue is Empty!";
	}
	else
	{
		element = queue[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			for (int i = 0; i < rear; i++)
			{
				queue[i] = queue[i + 1];
			}
			rear--;
		}
	}
	return element;
}

template<typename T>
T Queue<T>::peek()
{
	T element;
	if (isEmpty())
	{
		cout << "\nQueue is Empty!";
	}
	else
	{
		element = queue[front];
	}
	return element;
}
template<typename T>
bool Queue<T>::isFull()
{
	return (rear == size - 1);
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return (front == -1 && rear == -1);
}

template<typename T>
void Queue<T>::reset()
{
	rear = -1;
	front = -1;
}