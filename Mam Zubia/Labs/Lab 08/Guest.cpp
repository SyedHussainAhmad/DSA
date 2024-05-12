#include "Guest.h"

// Constructors
Guest::Guest() 
{
}

Guest::Guest(std::string name, std::string affiliation, std::string contactNumber) : name(name), affiliation(affiliation), contactNumber(contactNumber)
{
}

// Getters
std::string Guest::getName() const 
{
    return name;
}

std::string Guest::getAffiliation() const 
{
    return affiliation;
}

std::string Guest::getContactNumber() const 
{
    return contactNumber;
}

