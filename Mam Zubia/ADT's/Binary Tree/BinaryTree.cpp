#include "BinaryTree.h"

// Constructor
template <typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

// Destructor
template <typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}

// Clear the tree
template <typename T>
void BinaryTree<T>::clear(BTNode<T>* node) {
    if (node != nullptr) {
        clear(node->leftChild);
        clear(node->rightChild);
        delete node;
    }
}

template <typename T>
void BinaryTree<T>::clear() {
    clear(root);
    root = nullptr;
}

// Insert a new value into the tree
template <typename T>
void BinaryTree<T>::insert(T value) {
    BTNode<T>* newNode = new BTNode<T>(value);
    if (!root) {
        root = newNode;
        return;
    }

    // Level order traversal to find the right position
    queue<BTNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        BTNode<T>* current = q.front();
        q.pop();

        if (!current->leftChild) {
            current->leftChild = newNode;
            return;
        }
        else {
            q.push(current->leftChild);
        }

        if (!current->rightChild) {
            current->rightChild = newNode;
            return;
        }
        else {
            q.push(current->rightChild);
        }
    }
}

// Search for a value in the tree
template <typename T>
BTNode<T>* BinaryTree<T>::search(T value) const {
    if (!root) return nullptr;

    queue<BTNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        BTNode<T>* current = q.front();
        q.pop();

        if (current->data == value) {
            return current;
        }

        if (current->leftChild) {
            q.push(current->leftChild);
        }

        if (current->rightChild) {
            q.push(current->rightChild);
        }
    }

    return nullptr;
}

// Remove a value from the tree
template <typename T>
void BinaryTree<T>::remove(T value) {
    if (!root) return;

    BTNode<T>* toDelete = nullptr;
    BTNode<T>* lastNode = nullptr;
    BTNode<T>* parentOfLastNode = nullptr;
    queue<BTNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        lastNode = q.front();
        q.pop();

        if (lastNode->data == value) {
            toDelete = lastNode;
        }

        if (lastNode->leftChild) {
            parentOfLastNode = lastNode;
            q.push(lastNode->leftChild);
        }

        if (lastNode->rightChild) {
            parentOfLastNode = lastNode;
            q.push(lastNode->rightChild);
        }
    }

    if (toDelete) {
        toDelete->data = lastNode->data;

        if (parentOfLastNode->rightChild == lastNode) {
            delete parentOfLastNode->rightChild;
            parentOfLastNode->rightChild = nullptr;
        }
        else {
            delete parentOfLastNode->leftChild;
            parentOfLastNode->leftChild = nullptr;
        }
    }
}

// Heapify the tree to maintain max-heap property
template <typename T>
void BinaryTree<T>::heapifyMax() {
    if (!root) return;
    heapifyMax(root);
}

// Heapify the tree to maintain min-heap property
template <typename T>
void BinaryTree<T>::heapifyMin() {
    if (!root) return;
    heapifyMin(root);
}

// Heapify down the tree for max-heap property
template <typename T>
void BinaryTree<T>::heapifyMax(BTNode<T>* node) {
    if (!node) return;

    BTNode<T>* largest = node;
    BTNode<T>* left = node->leftChild;
    BTNode<T>* right = node->rightChild;

    if (left && left->data > largest->data) {
        largest = left;
    }

    if (right && right->data > largest->data) {
        largest = right;
    }

    if (largest != node) {
        swap(node->data, largest->data);
        heapifyMax(largest);
    }
}

// Heapify down the tree for min-heap property
template <typename T>
void BinaryTree<T>::heapifyMin(BTNode<T>* node) {
    if (!node) return;

    BTNode<T>* smallest = node;
    BTNode<T>* left = node->leftChild;
    BTNode<T>* right = node->rightChild;

    if (left && left->data < smallest->data) {
        smallest = left;
    }

    if (right && right->data < smallest->data) {
        smallest = right;
    }

    if (smallest != node) {
        swap(node->data, smallest->data);
        heapifyMin(smallest);
    }
}



// In-order traversal
template <typename T>
void BinaryTree<T>::inOrderTraversal(BTNode<T>* node) const {
    if (!node) return;
    inOrderTraversal(node->leftChild);
    cout << node->data << " ";
    inOrderTraversal(node->rightChild);
}

template <typename T>
void BinaryTree<T>::inOrderTraversal() const {
    inOrderTraversal(root);
    cout << endl;
}

// Pre-order traversal
template <typename T>
void BinaryTree<T>::preOrderTraversal(BTNode<T>* node) const {
    if (!node) return;
    cout << node->data << " ";
    preOrderTraversal(node->leftChild);
    preOrderTraversal(node->rightChild);
}

template <typename T>
void BinaryTree<T>::preOrderTraversal() const {
    preOrderTraversal(root);
    cout << endl;
}

// Post-order traversal
template <typename T>
void BinaryTree<T>::postOrderTraversal(BTNode<T>* node) const {
    if (!node) return;
    postOrderTraversal(node->leftChild);
    postOrderTraversal(node->rightChild);
    cout << node->data << " ";
}

template <typename T>
void BinaryTree<T>::postOrderTraversal() const {
    postOrderTraversal(root);
    cout << endl;
}

// Level-order traversal
template <typename T>
void BinaryTree<T>::levelOrderTraversal() const {
    if (!root) return;

    queue<BTNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        BTNode<T>* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->leftChild) {
            q.push(current->leftChild);
        }

        if (current->rightChild) {
            q.push(current->rightChild);
        }
    }
    cout << endl;
}

// Calculate the height of the tree
template <typename T>
int BinaryTree<T>::height(BTNode<T>* node) const {
    if (!node) return 0;
    int leftHeight = height(node->leftChild);
    int rightHeight = height(node->rightChild);
    return max(leftHeight, rightHeight) + 1;
}

// Get the maximum depth of the tree
template <typename T>
int BinaryTree<T>::maxDepth(BTNode<T>* node) {
    return height(node);
}

// Print nodes at a given level
template <typename T>
void BinaryTree<T>::printGivenLevel(BTNode<T>* node, int level) const {
    if (!node) return;
    if (level == 1) {
        cout << node->data << " ";
    }
    else if (level > 1) {
        printGivenLevel(node->leftChild, level - 1);
        printGivenLevel(node->rightChild, level - 1);
    }
}

template <typename T>
int BinaryTree<T>::diameterOfBinaryTree(BTNode<T>* root) {
    // Define a helper function to calculate the diameter recursively
    int res = 0;
    diameter(root, res);
    return res;
}

template <typename T>
int BinaryTree<T>::diameter(BTNode<T>* curr, int& res) {
    // Base case: if the current node is null, return 0
    if (!curr) return 0;

    // Recursively calculate the diameter of left and right subtrees
    int left = diameter(curr->leftChild, res);
    int right = diameter(curr->rightChild, res);

    // Update the maximum diameter encountered so far
    res = std::max(res, left + right);

    // Return the depth of the current node
    return std::max(left, right) + 1;
}

template <typename T>
int BinaryTree<T>::rec_func(BTNode<T>* root) {
    if (root == nullptr) return 0;
    int left_height = rec_func(root->leftChild);
    if (left_height == -1) return -1;
    int right_height = rec_func(root->rightChild);
    if (right_height == -1) return -1;
    if (abs(right_height - left_height) > 1) return -1;
    return max(++right_height, ++left_height);
}

template <typename T>
bool BinaryTree<T>::isBalanced(BTNode<T>* root) {
    if (root == nullptr) return true;
    if (rec_func(root) == -1) return false;
    return true;
}
// Template class instantiations for common types
template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<double>;
template class BinaryTree<char>;
template class BinaryTree<string>;
