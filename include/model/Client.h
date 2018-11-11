//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_CLIENT_H
#define ZAJECIA_2_CLIENT_H

#include <string>
#include "../../include/model/Address.h"
#include "Rent.h"

class Address;
class Rent;

class Client {

private:
    const std::string firstName;
    std::string lastName;
    const std::string personalID;
    Address *address;
    Address *registeredAddress;
    Rent *actuallRent;

public:


    //Client();

    Client(std::string firstName, std::string lastName, std::string personalID, Address *address,
           Address *registeredAddress, Rent *actuallRent);

    void modifyRent(Rent *wypozyczenie);

    std::string clientInfo();
    std::string clientName();

    Rent *getActuallRent() const;

    //Client(Address *registeredAddress);

    ~Client();
};


#endif //ZAJECIA_2_CLIENT_H
