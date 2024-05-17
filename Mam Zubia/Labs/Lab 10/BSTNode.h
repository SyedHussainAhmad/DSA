#ifndef BSTNODE_H
#define BSTNODE_H

template <typename T>
class BSTNode
{
public:
	T data;
	BSTNode* leftChild;
	BSTNode* rightChild;
	BSTNode();
	BSTNode(T);
	BSTNode(T , BSTNode, BSTNode);
	~BSTNode();
};

template <typename T>
BSTNode<T>::BSTNode()
{
	data = 0;
	leftChild = nullptr;
	rightChild = nullptr;
}

template<typename T>
BSTNode<T>::BSTNode(T value) : BSTNode()
{
	data = value;
}

template<typename T>
inline BSTNode<T>::BSTNode(T value, BSTNode left, BSTNode right)
{
	data = value;
	leftChild = left;
	rightChild = right;
}

template <typename T>
BSTNode<T>::~BSTNode()
{
	leftChild = nullptr;
	rightChild = nullptr;
}
#endif // !BSTNODE_H
