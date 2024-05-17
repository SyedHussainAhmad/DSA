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
    void inOrderTraversal(BSTNode<T>*) const;
    void preOrderTraversal(BSTNode<T>*) const;
    void postOrderTraversal(BSTNode<T>*) const;
    int height(BSTNode<T>*) const;
    int countNodes(BSTNode<T>*) const;
    int countLeaves(BSTNode<T>*) const;
    void clear(BSTNode<T>*);
    BSTNode<T>* findParent(BSTNode<T>*, T) const;
    BSTNode<T>* findMin(BSTNode<T>*) const;
    BSTNode<T>* findMax(BSTNode<T>*) const;
    int sumOfAllNodes(BSTNode<T>*) const;
    //bool findTarget(BSTNode<T>* node, int sum) const;
    int lowestCommonAncestor(BSTNode<T> *, int, int);

    void inorder(BSTNode<T>*, T*, int);
public:
    BST();
    ~BST();

    void insert(T value);
    BSTNode<T>* search(T value) const;
    void deleteNode(T value);
    void inOrderTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    T findMinimum() const;
    T findMaximum() const;
    int height() const;
    int countNodes() const;
    int countLeaves() const;
    bool isEmpty() const;
    void clear();
    T getRoot() const;
    BSTNode<T>* findParent(T value) const;
    T findSuccessor(T value) const;
    T findPredecessor(T value) const;
    int sumOfAllNodes() const;
    int sumOfLeftSide() const;
    int sumOfRightSide() const;
    bool findTarget(int sum) ;

    int lowestCommonAncestor(int , int);
    T * convertToArray();
};


// Private Functions:
template <typename T>
void BST<T>::inOrderTraversal(BSTNode<T>* node) const
{
    if (node != nullptr)
    {
        inOrderTraversal(node->leftChild);
        cout << node->data << " ";
        inOrderTraversal(node->rightChild);
    }
}

template <typename T>
void BST<T>::preOrderTraversal(BSTNode<T>* node) const
{
    if (node != nullptr)
    {
        cout << node->data << " ";
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
    }
}

template <typename T>
void BST<T>::postOrderTraversal(BSTNode<T>* node) const
{
    if (node != nullptr)
    {
        postOrderTraversal(node->leftChild);
        postOrderTraversal(node->rightChild);
        cout << node->data << " ";
    }
}

template <typename T>
int BST<T>::height(BSTNode<T>* node) const
{
    if (node == nullptr)
    {
        return -1;
    }
    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);
    return max(leftHeight, rightHeight) + 1;
}

template <typename T>
int BST<T>::countNodes(BSTNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return 1 + countNodes(node->leftChild) + countNodes(node->rightChild);
}

template <typename T>
int BST<T>::countLeaves(BSTNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    if (node->leftChild == nullptr && node->rightChild == nullptr)
    {
        return 1;
    }
    return countLeaves(node->leftChild) + countLeaves(node->rightChild);
}

template <typename T>
void BST<T>::clear(BSTNode<T>* node)
{
    if (node != nullptr)
    {
        clear(node->leftChild);
        clear(node->rightChild);
        delete node;
    }
}

template <typename T>
BSTNode<T>* BST<T>::findParent(BSTNode<T>* node, T value) const
{
    if (node == nullptr || (node->leftChild == nullptr && node->rightChild == nullptr))
    {
        return nullptr;
    }

    if ((node->leftChild != nullptr && node->leftChild->data == value) ||
        (node->rightChild != nullptr && node->rightChild->data == value))
    {
        return node;
    }

    if (value < node->data)
    {
        return findParent(node->leftChild, value);
    }
    else
    {
        return findParent(node->rightChild, value);
    }
}

template <typename T>
BSTNode<T>* BST<T>::findMin(BSTNode<T>* node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }
    while (node->leftChild != nullptr)
    {
        node = node->leftChild;
    }
    return node;
}

template <typename T>
BSTNode<T>* BST<T>::findMax(BSTNode<T>* node) const
{
    if (node == nullptr)
    {
        return nullptr;
    }
    while (node->rightChild != nullptr)
    {
        node = node->rightChild;
    }
    return node;
}

template <typename T>
int BST<T>::sumOfAllNodes(BSTNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->data + sumOfAllNodes(node->leftChild) + sumOfAllNodes(node->rightChild);
}

template <typename T>
bool BST<T>::findTarget(int tsum)
{
    //if (root == nullptr) return false;

    //tsum -= root->data;
    //if (root->leftChild == nullptr && root->rightChild == nullptr && tsum == 0) return true;

    //return findTarget(root->leftChild, tsum) || findTarget(root->rightChild, tsum);

    T *arr = new T[100];
    int size = 0;
    inorder(this->root, arr, size);
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

template<typename T>
inline int BST<T>::lowestCommonAncestor(BSTNode<T>* root, int node1, int node2)
{
    int value = -1;
    if (root->data < node1 && root->data > node1  || root->data > node1 && root->data < node1)
    {
        return root->data;
    }
    else if(root->data > node1 && root->data > node1)
    {
        value = lowestCommonAncestor(root->leftChild, node1,node2);
    }
    else
    {
        value = lowestCommonAncestor(root->rightChild, node1, node2);
    }
    return value;
}

template<typename T>
void BST<T>::inorder(BSTNode<T>* node, T* arr, int i)
{
    if (!node) return;
    inorder(node->leftChild, arr, i);
    arr[i] = node->data;
    inorder(node->rightChild, arr, i + 1);
}
// Public Functions:
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

template <typename T>
void BST<T>::inOrderTraversal() const
{
    inOrderTraversal(root);
    cout << endl;
}

template <typename T>
void BST<T>::preOrderTraversal() const
{
    preOrderTraversal(root);
    cout << endl;
}

template <typename T>
void BST<T>::postOrderTraversal() const
{
    postOrderTraversal(root);
    cout << endl;
}

template <typename T>
T BST<T>::findMinimum() const
{
    BSTNode<T>* minNode = findMin(root);
    if (minNode)
    {
        return minNode->data;
    }
    throw runtime_error("Tree is empty");
}

template <typename T>
T BST<T>::findMaximum() const
{
    BSTNode<T>* maxNode = findMax(root);
    if (maxNode)
    {
        return maxNode->data;
    }
    throw runtime_error("Tree is empty");
}

template <typename T>
int BST<T>::height() const
{
    return height(root) + 1;
}

template <typename T>
int BST<T>::countNodes() const
{
    return countNodes(root);
}

template <typename T>
int BST<T>::countLeaves() const
{
    return countLeaves(root);
}

template <typename T>
bool BST<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
void BST<T>::clear()
{
    clear(root);
    root = nullptr;
}

template <typename T>
T BST<T>::getRoot() const
{
    if (root)
    {
        return root->data;
    }
    throw runtime_error("Tree is empty");
}

template <typename T>
BSTNode<T>* BST<T>::findParent(T value) const
{
    return findParent(root, value);
}

template <typename T>
T BST<T>::findSuccessor(T value) const
{
    BSTNode<T>* node = search(value);
    if (node == nullptr)
    {
        throw runtime_error("Node not found");
    }

    if (node->rightChild != nullptr)
    {
        return findMin(node->rightChild)->data;
    }

    BSTNode<T>* parent = findParent(value);
    while (parent != nullptr && node == parent->rightChild)
    {
        node = parent;
        parent = findParent(node->data);
    }

    if (parent == nullptr)
    {
        throw runtime_error("No successor exists");
    }

    return parent->data;
}

template <typename T>
T BST<T>::findPredecessor(T value) const
{
    BSTNode<T>* node = search(value);
    if (node == nullptr)
    {
        throw runtime_error("Node not found");
    }

    if (node->leftChild != nullptr)
    {
        return findMax(node->leftChild)->data;
    }

    BSTNode<T>* parent = findParent(value);
    while (parent != nullptr && node == parent->leftChild)
    {
        node = parent;
        parent = findParent(node->data);
    }

    if (parent == nullptr)
    {
        throw runtime_error("No predecessor exists");
    }

    return parent->data;
}

template <typename T>
int BST<T>::sumOfAllNodes() const
{
    return sumOfAllNodes(root);
}

template <typename T>
int BST<T>::sumOfLeftSide() const
{
    return sumOfAllNodes(root->leftChild);
}

template <typename T>
int BST<T>::sumOfRightSide() const
{
    return sumOfAllNodes(root->rightChild);
}


template<typename T>
inline int BST<T>::lowestCommonAncestor(int node1, int node2)
{
    int value = lowestCommonAncestor(root, node1, node2);
    return value;
}

template<typename T>
T* BST<T>::convertToArray()
{
    T* arr = new T[100];
    return arr;
    //return convertToArray(root, arr, 0);
}

#endif // BST_H
