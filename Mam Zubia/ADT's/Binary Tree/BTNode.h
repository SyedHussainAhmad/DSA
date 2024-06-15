#ifndef BTNODE_H
#define BTNODE_H

template <typename T>
class BTNode
{
public:
	T data;
	BTNode* leftChild;
	BTNode* rightChild;
	BTNode();
	BTNode(T);
	BTNode(T, BTNode, BTNode);
	~BTNode();
};

template <typename T>
BTNode<T>::BTNode()
{
	leftChild = nullptr;
	rightChild = nullptr;
}

template<typename T>
BTNode<T>::BTNode(T value) : BTNode()
{
	data = value;
}

template<typename T>
inline BTNode<T>::BTNode(T value, BTNode left, BTNode right)
{
	data = value;
	leftChild = left;
	rightChild = right;
}

template <typename T>
BTNode<T>::~BTNode()
{
	leftChild = nullptr;
	rightChild = nullptr;
}
#endif // !BTNODE_H
