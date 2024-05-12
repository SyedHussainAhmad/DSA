#ifndef GUESTLIST_H
#define GUESTLIST_H

#include "Guest.h"

class Guestlist 
{
    static const int maxSize = 100;
    Guest* guests[maxSize];
    int priorities[maxSize];
    int rear;

public:
    Guestlist();
    ~Guestlist();

    void enqueue(Guest* guest, int priority);
    Guest* dequeue();
    Guest* top();

    bool isEmpty() const;
    bool isFull() const;
};

#endif // GUESTLIST_H
