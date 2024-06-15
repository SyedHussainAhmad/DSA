#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include"Task.h"

class PriorityQueue
{
	Task* heap;
	int capacity;
	int size;
	int parent(int i);
	int left(int i);
	void swap(Task& a, Task& b);
	int heapifyUp(int i);
	int heapifyDown(int i);
public:
	PriorityQueue(int capacity);
	void enqueue(Task task);
	Task dequeue();
	Task peek() const;
	bool isEmpty() const;
	int getSize() const;
	~PriorityQueue();
private:

};
#endif // !PRIORITY_QUEUE_H
