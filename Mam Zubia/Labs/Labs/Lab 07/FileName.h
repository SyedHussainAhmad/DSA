//#ifndef QUEUE_H
//#define QUEUE_H
//
//#include <iostream>
//
//template <typename T>
//class Queue {
//private:
//    T* array;
//    int maxSize;
//    int front;
//    int rear;
//
//public:
//    // Constructor
//    Queue(int size);
//
//    // Destructor
//    ~Queue();
//
//    // Operations
//    bool isEmpty() const;
//    bool isFull() const;
//    void enqueue(const T& item);
//    void dequeue();
//    const T& getFront() const;
//    void reset();
//};
//
//template <typename T>
//Queue<T>::Queue(int size) : maxSize(size), front(-1), rear(-1) {
//    array = new T[maxSize];
//}
//
//template <typename T>
//Queue<T>::~Queue() {
//    delete[] array;
//}
//
//template <typename T>
//bool Queue<T>::isEmpty() const {
//    return (front == -1 && rear == -1);
//}
//
//template <typename T>
//bool Queue<T>::isFull() const {
//    return (rear + 1) % maxSize == front;
//}
//
//template <typename T>
//void Queue<T>::enqueue(const T& item) {
//    if (!isFull()) {
//        if (isEmpty()) {
//            front = 0;
//            rear = 0;
//        }
//        else {
//            rear = (rear + 1) % maxSize; // Increment rear
//            if (rear == front) {
//                front = (front + 1) % maxSize; // Shift front when rear reaches front
//            }
//        }
//        array[rear] = item;
//    }
//    else {
//        std::cout << "Queue is full." << std::endl;
//    }
//}
//
//template <typename T>
//void Queue<T>::dequeue() {
//    if (!isEmpty()) {
//        if (front == rear) {
//            front = rear = -1; // Reset front and rear if the queue becomes empty
//        }
//        else {
//            front = (front + 1) % maxSize; // Increment front
//        }
//    }
//    else {
//        std::cout << "Queue is empty." << std::endl;
//    }
//}
//
//template <typename T>
//const T& Queue<T>::getFront() const {
//    if (!isEmpty()) {
//        return array[front];
//    }
//    else {
//        std::cout << "Queue is empty." << std::endl;
//        exit(EXIT_FAILURE);
//    }
//}
//
//template <typename T>
//void Queue<T>::reset() {
//    front = rear = -1;
//}
//
//#endif
