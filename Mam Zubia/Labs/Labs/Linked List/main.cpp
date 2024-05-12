#include "DoubleLinkedList.h"

int main()
{
    // Create an empty linked list
    DoubleLinkedList<int> myList;

    // Add elements to the linked list
    myList.addToTail(10);
    myList.addToTail(20);
    myList.addToTail(30);
    myList.addToTail(40);
    myList.addToTail(50);

    cout << "Original List: ";
    myList.print();
    cout << endl;

    // Test deleteFromHead
    int deletedHead = myList.deleteFromHead();
    cout << "After deleting head (" << deletedHead << "): ";
    myList.print();
    cout << endl;

    // Test deleteFromTail
    int deletedTail = myList.deleteFromTail();
    cout << "After deleting tail (" << deletedTail << "): ";
    myList.print();
    cout << endl;

    // Test search
    int searchValue = 20;
    int position = myList.search(searchValue);
    if (position != -1) {
        cout << "Position of " << searchValue << ": " << position << endl;
    }
    else {
        cout << searchValue << " not found in the list." << endl;
    }

    // Test count
    int countValue = 30;
    int count = myList.count(countValue);
    cout << "Count of " << countValue << ": " << count << endl;

    // Test insert
    int insertValue = 25;
    int insertPosition = 2;
    myList.insert(insertValue, insertPosition);
    cout << "After inserting " << insertValue << " at position " << insertPosition << ": ";
    myList.print();
    cout << endl;

    // Test replace
    int replaceValue = 35;
    int replacePosition = 3;
    myList.replace(replaceValue, replacePosition);
    cout << "After replacing value at position " << replacePosition << " with " << replaceValue << ": ";
    myList.print();
    cout << endl;

    // Test size
    cout << "Size of the list: " << myList.size() << endl;

    // Test reverse
    cout << "Reversed List: ";
    myList.reverse();
    myList.print();
    cout << endl;

    // Test sort
    cout << "Sorted List (Ascending): ";
    myList.sort(true);
    myList.print();
    cout << endl;

    cout << "Sorted List (Descending): ";
    myList.sort(false);
    myList.print();
    cout << endl;

    // Test merge
    DoubleLinkedList<int> secondList;
    secondList.addToTail(15);
    secondList.addToTail(25);
    secondList.addToTail(35);

    DoubleLinkedList<int> mergedList = myList.merge(secondList);
    cout << "Merged List: ";
    mergedList.print();
    cout << endl;

    // Test unique
    cout << "Unique List: ";
    mergedList.unique();
    mergedList.print();
    cout << endl;

    // Test clear
    cout << "Clearing the list..." << endl;
    mergedList.clear();
    cout << "List cleared. Is empty: " << (mergedList.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
