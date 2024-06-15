#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main() {
    // Create a binary tree
    BinaryTree<int> binaryTree;

    // Insert some values
    binaryTree.insert(50);
    binaryTree.insert(30);
    binaryTree.insert(70);
    binaryTree.insert(20);
    binaryTree.insert(40);
    binaryTree.insert(60);
    binaryTree.insert(80);

    // Test traversal functions
    cout << "In-order traversal: ";
    binaryTree.inOrderTraversal(); // Should output: 20 30 40 50 60 70 80
    cout << "Pre-order traversal: ";
    binaryTree.preOrderTraversal(); // Should output: 50 30 20 40 70 60 80
    cout << "Post-order traversal: ";
    binaryTree.postOrderTraversal(); // Should output: 20 40 30 60 80 70 50
    cout << "Level-order traversal: ";
    binaryTree.levelOrderTraversal(); // Should output: 50 30 70 20 40 60 80

    // Test search function
    int searchValue = 60;
    BTNode<int>* searchResult = binaryTree.search(searchValue);
    if (searchResult) {
        cout << "Value " << searchValue << " found in the tree." << endl;
    }
    else {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    // Test remove function
    int removeValue = 30;
    binaryTree.remove(removeValue);
    cout << "After removing " << removeValue << ": ";
    binaryTree.inOrderTraversal(); // Should output: 20 40 50 60 70 80

    // Test heapify operations
    cout << "Heapify max: ";
    binaryTree.heapifyMax();
    binaryTree.inOrderTraversal(); // Should output: 80 70 60 50 40 20
    cout << "Heapify min: ";
    binaryTree.heapifyMin();
    binaryTree.inOrderTraversal(); // Should output: 20 40 50 60 70 80

    return 0;
}
