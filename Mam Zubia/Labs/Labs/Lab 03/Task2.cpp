#ifndef MIN_STACK_H
#define MIN_STACK_H
#include "Stack.h"

class MinStack 
{
    Stack<int> mainStack;
    Stack<int> minStack;

public:
    MinStack() {}

    void push(int value) 
    {
        mainStack.push(value);
        if (minStack.isEmpty() || value <= minStack.top()) 
        {
            minStack.push(value);
        }
    }

    void pop() 
    {
        if (mainStack.top() == minStack.top()) 
        {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() 
    {
        return mainStack.top();
    }

    int getMin() 
    {
        return minStack.top();
    }
};

#endif // !MIN_STACK_H

//int main() 
//{
//    MinStack minStack;
//
//    minStack.push(-5);
//    minStack.push(1);
//    minStack.push(2);
//    cout << "getMin: " << minStack.getMin() << endl;
//    minStack.push(-6);
//    cout << "getMin: " << minStack.getMin() << endl;
//    cout << "top: " << minStack.top() << endl;
//    minStack.pop();
//    cout << "top: " << minStack.top() << endl;
//    cout << "getMin: " << minStack.getMin() << endl;
//
//    return 0;
//}