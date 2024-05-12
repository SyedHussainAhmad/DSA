//#include <iostream>
//#include "Queue.h"
//
//int main() {
//    // Create a queue with size 5
//    Queue<int> q(3);
//
//    // Test isEmpty() on an empty queue
//    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
//
//    // Enqueue elements
//    q.enQueue(10);
//    q.enQueue(20);
//    q.enQueue(30);
//
//    // Test isEmpty() after enqueueing elements
//    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
//
//    // Test isFull() on a non-full queue
//    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
//
//    // Test getFront()
//    cout << "Front element: " << q.deQueue() << endl;
//
//    // Dequeue elements
//    q.deQueue();
//
//    // Test getFront() after deQueueing elements
//    cout << "Front element: " << q.deQueue() << endl;
//
//    // Test reset() function
//    q.reset();
//    cout << "Is queue empty after reset? " << (q.isEmpty() ? "Yes" : "No") << endl;
//
//    return 0;
//}
