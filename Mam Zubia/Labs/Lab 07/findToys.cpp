#include<iostream>
#include"Queue.h"
using namespace std;

int unableToCollectToys(int *children, int childrenSize, int * toys, int toysSize)
{
    Queue<int> childrenQueue;
    for (int i = 0; i < childrenSize; i++)
    {
        childrenQueue.enQueue(children[i]);
    }
    int inable = 0;

    for (int i = 0; i < toysSize; i++)
    {
        int value = childrenQueue.deQueue();
        if (value != toys[i])
        {
            childrenQueue.enQueue(value);
            inable++;
        }
    }

    return inable;
}

int main() 
{
    int children[] = { 1, 1, 1, 0, 0, 1 };
    int toys[] = { 1, 0, 0, 0, 1, 1 };
    int childrenSize = 6;
    int toysSize = 6;

    cout << unableToCollectToys(children, childrenSize, toys, toysSize) << endl;

    return 0;
}

