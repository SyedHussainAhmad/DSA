#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template<typename T>
class Stack 
{
    T elements[MAX_SIZE];
    int topIndex;

public:
    Stack() : topIndex(-1) 
    {}

    bool isEmpty() const 
    {
        return topIndex == -1;
    }

    bool isFull() const 
    {
        return topIndex == MAX_SIZE - 1;
    }

    void push(const T& value) 
    {
        if (isFull()) 
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        elements[++topIndex] = value;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    T& top() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty!";
        }
        return elements[topIndex];
    }
};


#endif // !STACK_H
