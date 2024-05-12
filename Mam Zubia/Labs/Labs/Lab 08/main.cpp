#include "Guestlist.h"

int main() 
{
    Guest guest1("Omair", "Educative", "1234567890");
    Guest guest2("umer", "Devsinc", "9876543210");
    Guest guest3("Hussain", "PUCIT", "5551234567");
    Guest guest4("Ahmad", "PUCIT", "9998887776");
    Guest guest5("zaydi", "Pucit", "1112223334");

    Guestlist guestlist;

    guestlist.enqueue(&guest1, 5);
    guestlist.enqueue(&guest2, 3);
    guestlist.enqueue(&guest3, 2);
    guestlist.enqueue(&guest4, 4);
    guestlist.enqueue(&guest5, 1);

    // Dequeue and print guests until the guestlist is empty
    while (!guestlist.isEmpty()) 
    {
        Guest* guest = guestlist.dequeue();
        cout << "Dequeued guest: " << guest->getName() << " (" << guest->getAffiliation() << ", " << guest->getContactNumber() << ")" << endl;
    }

    return 0;
}
