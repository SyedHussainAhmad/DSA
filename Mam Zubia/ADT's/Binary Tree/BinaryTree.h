#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <queue>
#include <iostream>
using namespace std;
#include "BTNode.h"

template <typename T>
class BinaryTree
{
private:
    BTNode<T>* root;
    void heapifyMin(BTNode<T>* node);
    void heapifyMax(BTNode<T>* node);
    void inOrderTraversal(BTNode<T>*) const;
    void preOrderTraversal(BTNode<T>*) const;
    void postOrderTraversal(BTNode<T>*) const;
    void clear(BTNode<T>*);
    int height(BTNode<T>* node) const;
    void printGivenLevel(BTNode<T>* node, int level) const;
    int diameter(BTNode<T>* curr, int& res);
    int rec_func(BTNode<T>* root);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(T value);
    BTNode<T>* search(T value) const;
    void remove(T value);
    void heapifyMax();
    void heapifyMin();

    void inOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    void levelOrderTraversal() const;
    void clear();
    int maxDepth(BTNode<T>* root);
    int diameterOfBinaryTree(BTNode<T>* root);

    bool isBalanced(BTNode<T>* root);
};

#endif // BINARY_TREE_H