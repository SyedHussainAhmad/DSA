#include"Node.h"

template<typename T>
Node<T>::Node()
{
	next = nullptr;
	prev = nullptr;
}

template<typename T>
Node<T>::Node(T val)
{
	data = val;
	next = nullptr;
	prev = nullptr;
}
template<typename T>
Node<T>::Node(T val, Node<T>* n, Node<T>* p)
{
	data = val;
	next = n;
	prev = p;
}
