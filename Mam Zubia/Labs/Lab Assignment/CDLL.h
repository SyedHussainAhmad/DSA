#ifndef CDLL_H
#define CDLL_H
#include<iostream>
using namespace std;
#include"Node.h"

template<typename T>
class CDLL
{
	Node<T>* head;
	Node <T>* searchAddress(const T& key);
	void copyFrom(const CDLL<T>& other);

public:
	CDLL();
	~CDLL();
	CDLL<T>& operator = (const CDLL<T>& ref);
	CDLL<T>(const CDLL<T>& ref);
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeAtHead();
	void removeAtTail();
	void removeAfter(T key);
	void removeBefore(T key);
	void remove(T key);
	void display();
	int getLength();
	void rotateCircularDLL(int times);
	bool targetSum(int target);
};

template class CDLL<int>;
#endif