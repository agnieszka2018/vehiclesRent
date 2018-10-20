//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_CLIENT_H
#define ZAJECIA_2_CLIENT_H

#include <string>
#include "../../include/model/Address.h"

class Address;

class Client {

private:
    const std::string firstName;
    std::string lastName;
    const std::string personalID;
    Address *address = nullptr;
    Address *registeredAddress = nullptr;

public:
    std::string clientInfo();

    //Client();

    Client(std::string firstName, std::string lastName, std::string personalID, Address *address = nullptr,
           Address *registeredAddress = nullptr);

    ~Client();
};


#endif //ZAJECIA_2_CLIENT_H
