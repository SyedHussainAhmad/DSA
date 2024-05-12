#include <iostream>
using namespace std;

#include "Queue.h"
template<typename T>
class Stack 
{
private:
    Queue<T> q;

public:
    Stack()
    {}

    void push(T x)
    {
        q.enQueue(x);
        for (int i = 0; i < q.getSize() - 1; i++)
        {
            T front_element = q.deQueue();
            q.enQueue(front_element);
        }
    }

    T pop()
    {
        return q.deQueue();
    }

    T top()
    {
        return q.peek();
    }

    bool empty()
    {
        return q.isEmpty();
    }
};