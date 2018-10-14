//
// Created by pobi on 14.10.18.
//

#include "../../include/model/Client.h"

Client::Client()
{
    std::cout<<"konstruktor";
}

Client::Client(std::string firstName, std::string lastName, std::string personalID)
{

    this->firstName=firstName;
    this->lastName=lastName;
    this->personalID=personalID;
    std::cout<<"konstruktor";
}

~Client::Client() {
    std::cout<<"destruktor";
}

std::string Client::clientInfo() {
    return firstName + lastName + personalID;
}