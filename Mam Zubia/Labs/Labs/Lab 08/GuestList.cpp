#include "Guestlist.h"

Guestlist::Guestlist() : rear(-1) 
{
}

Guestlist::~Guestlist() 
{
    while (!isEmpty()) 
    {
        delete dequeue();
    }
}

void Guestlist::enqueue(Guest* guest, int priority) 
{
    if (isFull()) 
    {
        return;
    }
    rear++;
    guests[rear] = guest;
    priorities[rear] = priority;
}

// Dequeue operation
Guest* Guestlist::dequeue() 
{
    if (isEmpty()) 
    {
        return nullptr;
    }

    // Finding high Priority Guest.
    int maxPriorityIndex = 0;
    for (int i = 1; i <= rear; i++) 
    {
        if (priorities[i] > priorities[maxPriorityIndex]) 
        {
            maxPriorityIndex = i;
        }
    }

    // Getting high Priority Guest.
    Guest* dequeuedGuest = guests[maxPriorityIndex];

    // Shifting the array.
    for (int i = maxPriorityIndex; i < rear; i++)
    {
        guests[i] = guests[i + 1];
        priorities[i] = priorities[i + 1];
    }
    rear--;
    return dequeuedGuest;
}

// Top Operation
Guest* Guestlist::top() 
{
    if (isEmpty()) 
    {
        return nullptr;
    }
    int maxPriorityIndex = 0;
    for (int i = 1; i <= rear; i++) 
    {
        if (priorities[i] > priorities[maxPriorityIndex]) 
        {
            maxPriorityIndex = i;
        }
    }
    return guests[maxPriorityIndex];
}

// Check if the guest list is empty 
bool Guestlist::isEmpty() const 
{
    return rear == -1;
}

// Check if the guest list is full 
bool Guestlist::isFull() const 
{
    return rear == maxSize - 1;
}
