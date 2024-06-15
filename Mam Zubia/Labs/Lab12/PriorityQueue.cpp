#include "PriorityQueue.h"

int PriorityQueue::parent(int i)
{
	return i/2;
}

int PriorityQueue::left(int i)
{
	return 2*i;
}

void PriorityQueue::swap(Task& a, Task& b)
{
	Task& temp = a;
	a = b;
	b = temp;
}

int PriorityQueue::heapifyUp(int i)
{
	while (i > 1)
	{
		int pr = parent(i);
		if (heap[pr].priority < heap[i].priority)
		{
			swap(heap[pr], heap[i]);
			i = pr;
		}
		else
			return 0;
	}
	return 1;
}

int PriorityQueue::heapifyDown(int i)
{
	int lastIndex = size - 1;
	swap(heap[1],heap[size]);
	while (i < lastIndex)
	{
		int lft = left(i);
		int right = left(i) + 1;
		int larger = heap[lft].priority > heap[right].priority ? lft : right;
		if (heap[i].priority < heap[larger].priority)
		{
			swap(heap[larger], heap[i]);
			i = larger;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

PriorityQueue::PriorityQueue(int capacity)
{
	size = 0;
	this->capacity = capacity;
	heap = new Task[ capacity ];
}

void PriorityQueue::enqueue(Task task)
{
	if (size==capacity)
	{
		return;
	}
	size++;
	heap[size] = task;
	heapifyUp(size);
}

Task PriorityQueue::dequeue()
{
	if (!isEmpty())
	{
		Task dequeued = heap[1];
		heapifyDown(1);
		size--;
		return dequeued;
	}
}

Task PriorityQueue::peek() const
{
	return heap[1];
}

bool PriorityQueue::isEmpty() const
{
	return size == 0;
}

int PriorityQueue::getSize() const
{
	return size;
}

PriorityQueue::~PriorityQueue()
{
	delete[] heap;
	size = 0;
	capacity = 0;
}

