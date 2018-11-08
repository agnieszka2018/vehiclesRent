//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_CLIENT_H
#define ZAJECIA_2_CLIENT_H

#include <string>
#include "../../include/model/Address.h"
#include "Rent.h"

class Address;
class Rent;             //???

class Client {

public:
    const std::string firstName;
    std::string lastName;
    const std::string personalID;
    Address *address = nullptr;
    Address *registeredAddress = nullptr;
    Rent *actuallRent = nullptr;

public:

    //Client();

    Client(std::string firstName, std::string lastName, std::string personalID, Address *address = nullptr,
           Address *registeredAddress = nullptr, Rent *actuallRent = nullptr);

    void modifyRent(Rent *);

    std::string clientInfo();

    std::string getClient();

    //Client(Address *registeredAddress);

    ~Client();

    Rent *getActuallRent() const;
};


#endif //ZAJECIA_2_CLIENT_H
