//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_CLIENT_H
#define ZAJECIA_2_CLIENT_H

#include <string>
#include "Address.h"
#include "Rent.h"
#include "ClientType.h"

class Address;
class Rent;
class ClientType;

class Client {

private:
    const std::string firstName;
    const std::string lastName;
    const std::string personalID;
    Address *address;
    Address *registeredAddress;
    Rent *actuallRent;
    ClientType *clientType;
    int allClientRents; //zakończone wypożyczenia klienta

public:
    void setClientType(ClientType *clientType);

    //Client();

    Client(std::string firstName, std::string lastName, std::string personalID, Address *address,
               Address *registeredAddress, Rent *actuallRent, ClientType *clientType);

    void modifyRent(Rent *wypozyczenie);

    std::string clientInfo();
    std::string clientName();

    Rent *getActuallRent() const;

    //Client(Address *registeredAddress);

    ~Client();
};


#endif //ZAJECIA_2_CLIENT_H
