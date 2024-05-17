#include <iostream>
#include "BST.h"

using namespace std;

int main() 
{
    BST<int> tree;

    // Insert elements
    tree.insert(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);

    cout << tree.findTarget(9);
    // In-order traversal
    cout << "In-order traversal: ";
    tree.inOrderTraversal();

    // Attempt to insert a duplicate
    tree.deleteNode(2);
    tree.deleteNode(7);

    // In-order traversal
    cout << "In-order traversal: ";
    tree.inOrderTraversal();

    return 0;
}
