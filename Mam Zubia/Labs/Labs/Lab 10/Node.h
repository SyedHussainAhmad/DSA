#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node();
	Node(T val);
	Node(T val, Node<T>* next, Node<T>* prev);
};
template class Node<int>;
#endif // !NODE_H
