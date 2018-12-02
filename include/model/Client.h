//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_CLIENT_H
#define ZAJECIA_2_CLIENT_H

#include <string>
#include "Address.h"
#include "Rent.h"
#include "ClientType.h"
#include <vector>

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
    //Rent *actuallRent;
    std::vector<Rent *> clientActuallRents;  //aktualne wypożyczenia klienta
    std::vector<Rent *> allClientRents; //zakończone wypożyczenia klienta
    ClientType *clientType;

public:
    void setClientType(ClientType *clientType);

    ClientType *getClientType();

    //Client();

    Client(std::string firstName, std::string lastName, std::string personalID, Address *address,
           Address *registeredAddress, ClientType *clientType);

    void addRent(Rent *rentFromRent);

    void deleteRent(Rent *);

    std::string clientInfo();

    std::string clientName();

    std::vector<Rent *> getClientActuallRents();

    //Client(Address *registeredAddress);

    ~Client();
};


#endif //ZAJECIA_2_CLIENT_H
