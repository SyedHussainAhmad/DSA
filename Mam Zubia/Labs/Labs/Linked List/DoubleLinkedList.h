#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include<iostream>
using namespace std;
#include"DNode.h"

template <typename T>
class DoubleLinkedList
{
	DNode<T>* head;
	DNode<T>* tail;
	void mySwap(T& ,T&);
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList<T>& other);
	DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other);
	bool isEmpty();
	void addToHead(T);
	void addToTail(T);
	T deleteFromHead();
	T deleteFromTail();
	int search(T);
	int count(T);
	void insert(T, int);
	void replace(T, int);
	int size();
	void reverse();
	void sort(bool);
	DoubleLinkedList<T> merge(const DoubleLinkedList<T> &);
	void clear();
	void unique();
	void print();
};
#endif // !DOUBLE_LINKED_LIST_H

// Private Functions:
template <typename T>
void DoubleLinkedList<T>::mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// Public Functions:
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& other)
{
	head = nullptr;
	tail = nullptr;
	DNode<T>* temp = other.head;
	while (temp != nullptr) 
	{
		addToTail(temp->data);
		temp = temp->next;
	}
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& other)
{
	if (this == &other) return *this; 

	while (head != nullptr) 
	{
		deleteFromHead();
	}

	DNode<T>* temp = other.head;
	while (temp != nullptr) 
	{
		addToTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty()
{
	return head == nullptr;
}

template <typename T>
void DoubleLinkedList<T>::addToHead(T val)
{
	if (head == nullptr)
	{
		head = new DNode<T>(val);
		tail = head;
	}
	else
	{
		head->prev = new DNode<T>(val, head);
		head = head->prev;
	}
}

template <typename T>
void DoubleLinkedList<T>::addToTail(T val)
{
	if (head == 0)
	{
		head = new DNode<T>(val);
		tail = head;
	}
	else
	{
		tail = new DNode<T>(val, nullptr, tail);
		tail->prev->next = tail;
	}
}

template <typename T>
T DoubleLinkedList<T>::deleteFromHead()
{
	T val = head->data;
	if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = head->next;
		delete head->prev;
		head->prev = nullptr;
	}
	return val;
}

template <typename T>
T DoubleLinkedList<T>::deleteFromTail()
{
	T val = tail->data;
	if (head == tail)
	{
		delete head;
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	return val;
}

template <typename T>
int DoubleLinkedList<T>::search(T value)
{
	int index = 0;
	DNode<T>* current = head;
	bool findFlag = false;
	while (current != nullptr && !findFlag) 
	{
		if (current->data == value) 
		{
			findFlag = true;;
		}
		current = current->next;
		index++;
	}
	return findFlag ? index : -1;
}

template <typename T>
int DoubleLinkedList<T>::count(T value)
{
	int count = 0;
	DNode<T>* current = head;
	while (current != nullptr) 
	{
		if (current->data == value)
			count++;

		current = current->next;
	}
	return count;
}

template <typename T>
void DoubleLinkedList<T>::insert(T val, int position)
{
	if (position < 0)
		return;

	if (position == 0) 
	{
		addToHead(val);
		return;
	}

	DNode<T>* temp = head;
	for (int i = 0; i < position - 1 && temp != nullptr; i++)
	{
		temp = temp->next;
	}

	if (temp == nullptr || temp == tail)
	{
		addToTail(val);
	}
	else
	{
		DNode<T>* newNode = new DNode<T>(val, temp->next, temp);
		temp->next->prev = newNode;
		temp->next = newNode;
	}
}

template <typename T>
void DoubleLinkedList<T>::replace(T val, int position)
{
	if (position < 0 || isEmpty())
		return;


	DNode<T>* temp = head;
	for (int i = 0; i < position && temp != nullptr; i++)
	{
		temp = temp->next;
	}

	if (temp != nullptr)
	{
		temp->data = val;
	}
}

template <typename T>
int DoubleLinkedList<T>::size()
{
	int count = 0;
	DNode<T>* current = head;
	while (current != nullptr) 
	{
		count++;
		current = current->next;
	}
	return count;
}

template <typename T>
DoubleLinkedList<T> DoubleLinkedList<T>::merge(const DoubleLinkedList<T>& other)
{
	DoubleLinkedList<T> mergedList;

	DNode<T>* current1 = head;
	DNode<T>* current2 = other.head;

	while (current1 != nullptr && current2 != nullptr) 
	{
		if (current1->data <= current2->data) {
			mergedList.addToTail(current1->data);
			current1 = current1->next;
		}
		else 
		{
			mergedList.addToTail(current2->data);
			current2 = current2->next;
		}
	}

	while (current1 != nullptr) 
	{
		mergedList.addToTail(current1->data);
		current1 = current1->next;
	}

	while (current2 != nullptr) 
	{
		mergedList.addToTail(current2->data);
		current2 = current2->next;
	}

	return mergedList;
}

template <typename T>
void DoubleLinkedList<T>::clear()
{
	while (head != nullptr) 
	{
		deleteFromHead();
	}
}

template <typename T>
void DoubleLinkedList<T>::reverse()
{
	if (isEmpty() || head == tail) return;

	DNode<T>* current = head;
	head = tail;
	tail = current;
	DNode<T>* temp = nullptr;
	while (current != nullptr) 
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != nullptr) 
	{
		head = temp->prev;
	}

}

template <typename T>
void DoubleLinkedList<T>::sort(bool ascending)
{
	if (isEmpty() || head == tail) return;

	bool swapped;
	DNode<T>* ptr1;
	DNode<T>* lptr = nullptr;

	do 
	{
		swapped = false;
		ptr1 = head;

		while (ptr1->next != lptr) 
		{
			if ((ascending && ptr1->data > ptr1->next->data) || (!ascending && ptr1->data < ptr1->next->data)) 
			{
				mySwap(ptr1->data, ptr1->next->data);
				swapped = true;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} 
	while (swapped);
}

template <typename T>
void DoubleLinkedList<T>::unique()
{
	if (isEmpty() || head == tail) return;

	DNode<T>* current = head;
	while (current != nullptr && current->next != nullptr) 
	{
		DNode<T>* runner = current;
		while (runner->next != nullptr) 
		{
			if (current->data == runner->next->data) 
			{
				DNode<T>* temp = runner->next;
				runner->next = runner->next->next;
				if (runner->next != nullptr) 
					runner->next->prev = runner;
				else 
					tail = runner;

				delete temp;
			}
			else
				runner = runner->next;
		}
		current = current->next;
	}
}
template <typename T>
void DoubleLinkedList<T>::print()
{
	DNode<T>* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}