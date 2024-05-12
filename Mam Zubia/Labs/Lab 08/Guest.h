#ifndef GUEST_H
#define GUEST_H

#include <string>
#include <iostream>
using namespace std;

class Guest 
{
private:
    string name;
    string affiliation;
    string contactNumber;

public:
    // Constructors
    Guest();
    Guest(string name, string affiliation, string contactNumber);

    // Getters
    string getName() const;
    string getAffiliation() const;
    string getContactNumber() const;
};

#endif // GUEST_H
