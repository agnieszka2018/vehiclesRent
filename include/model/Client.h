//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_CLIENT_H
#define ZAJECIA_2_CLIENT_H

#include <string>
#include <memory>
#include "Address.h"
#include "Rent.h"
#include "Vehicle.h"
#include "ClientType.h"
#include "ClientException.h"
#include <vector>

//class Vehicle;
class Rent;

typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;


class Client {

private:
    const std::string firstName;
    const std::string lastName;
    const std::string personalID;
    AddressPtr address;
    AddressPtr registeredAddress;
    std::vector<RentPtr> clientActuallRents;  //aktualne wypożyczenia klienta
    std::vector<RentPtr> allClientRents; //zakończone wypożyczenia klienta
    ClientTypePtr clientType;

public:
    void setClientType(ClientTypePtr clientType);

    ClientTypePtr getClientType();

    Client(std::string firstName, std::string lastName, std::string personalID, ClientTypePtr clientType,
           AddressPtr address,
           AddressPtr registeredAddress);

    void addRent(RentPtr rentFromRent);

    void deleteRent(RentPtr);

    std::string clientInfo();

    std::string getFirstName();

    std::string getLastName();

    std::string getPersonalID();

    std::vector<RentPtr> getClientActuallRents();

    std::vector<RentPtr> getAllClientRents();

    double calculatePriceWithDiscount(RentPtr);

    AddressPtr getAddress();

    AddressPtr getRegisteredAddress();

    bool operator==(Client &);

    ~Client();
};


#endif //ZAJECIA_2_CLIENT_H
