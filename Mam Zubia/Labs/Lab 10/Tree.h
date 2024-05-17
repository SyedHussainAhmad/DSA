#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;
#include "BSTNode.h"

template <typename T>
class BST
{
private:
    BSTNode<T>* root;
    int lowestCommonAncestor(BSTNode<T>*, int, int);
    void inorder(BSTNode<T>*, T*, int&);
public:
    BST();
    ~BST();

    void insert(T value);
    BSTNode<T>* search(T value) const;
    void deleteNode(T value);
    int lowestCommonAncestor(int, int);
    bool findTarget(int);
};

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST()
{
    clear(root);
}

template <typename T>
void BST<T>::insert(T value)
{
    BSTNode<T>* newNode = new BSTNode<T>(value);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    BSTNode<T>* current = root;
    BSTNode<T>* parent = nullptr;

    bool findFlag = false;
    while (current != nullptr && !findFlag)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->leftChild;
        }
        else if (value > current->data)
        {
            current = current->rightChild;
        }
        else
        {
            findFlag = true;
        }
    }

    if (current != nullptr)
    {
        cout << "Value already existed...\n";
        return;
    }

    if (value < parent->data)
    {
        parent->leftChild = newNode;
    }
    else
    {
        parent->rightChild = newNode;
    }
}

template <typename T>
BSTNode<T>* BST<T>::search(T value) const
{
    BSTNode<T>* current = root;
    bool findFlag = false;
    while (current != nullptr && !findFlag)
    {
        if (value < current->data)
        {
            current = current->leftChild;
        }
        else if (value > current->data)
        {
            current = current->rightChild;
        }
        else
        {
            findFlag = true;
        }
    }
    return current ? current : nullptr;
}

//Task 1:
template <typename T>
void BST<T>::deleteNode(T value)
{
    BSTNode<T>* current = root;
    BSTNode<T>* parent = nullptr;

    while (current != nullptr && current->data != value)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }

    if (current == nullptr)
    {
        return;
    }

    if (current->leftChild != nullptr && current->rightChild != nullptr)
    {
        BSTNode<T>* successorParent = current;
        BSTNode<T>* successor = current->rightChild;
        while (successor->leftChild != nullptr)
        {
            successorParent = successor;
            successor = successor->leftChild;
        }
        current->data = successor->data;
        current = successor;
        parent = successorParent;
    }

    BSTNode<T>* child = (current->leftChild != nullptr) ? current->leftChild : current->rightChild;

    if (parent == nullptr)
    {
        root = child;
    }
    else if (parent->leftChild == current)
    {
        parent->leftChild = child;
    }
    else
    {
        parent->rightChild = child;
    }

    delete current;
}

//Task 2:
template<typename T>
int BST<T>::lowestCommonAncestor(BSTNode<T>* root, int node1, int node2)
{
    int value = -1;
    if (root->data < node1 && root->data > node1 || root->data > node1 && root->data < node1)
    {
        return root->data;
    }
    else if (root->data > node1 && root->data > node1)
    {
        value = lowestCommonAncestor(root->leftChild, node1, node2);
    }
    else
    {
        value = lowestCommonAncestor(root->rightChild, node1, node2);
    }
    return value;
}

template<typename T>
int BST<T>::lowestCommonAncestor(int node1, int node2)
{
    int value = lowestCommonAncestor(root, node1, node2);
    return value;
}

//Task 3:
template<typename T>
void BST<T>::inorder(BSTNode<T>* node, T* arr, int& i)
{
    if (!node) return;
    inorder(node->leftChild, arr, i);
    arr[i] = node->data;
    inorder(node->rightChild, arr, i + 1);
}

template <typename T>
bool BST<T>::findTarget(int tsum)
{
    T* arr = new T[100];
    int size = 0;
    inorder(root, arr, size);
    int i = 0, j = size - 1;
    while (i != j)
    {
        if (arr[i] + arr[j] == tsum)
        {
            return true;
        }
        if (arr[i] + arr[j] > tsum)
        {
            j--;
        }
        if (arr[i] + arr[j] < tsum)
        {
            i++;
        }
    }
    return false;
}
#endif // BST_H
