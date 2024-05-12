#ifndef D_NODE_H
#define D_NODE_H

template <typename T>
class DNode
{
public:
	T data;
	DNode* next;
	DNode* prev;
	DNode();
	DNode(T, DNode* = nullptr, DNode* = nullptr);
	T getData();
};
#endif // !D_NODE_H

template <typename T>
DNode<T>::DNode()
{
	next = nullptr;
	prev = nullptr;
}

template <typename T>
DNode<T>::DNode(T d, DNode* n, DNode* p)
{
	data = d;
	next = n;
	prev = p;
}

template <typename T>
T DNode<T>::getData()
{
	return data;
}