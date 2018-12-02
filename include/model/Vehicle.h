//
// Created by pobi on 29.10.18.
//

#ifndef POBIZ01_VEHICLE_H
#define POBIZ01_VEHICLE_H

#include <string>
#include <memory>
#include "Client.h"
#include "Car.h"

typedef std::shared_ptr<Client> ClientPtr;

class Vehicle {

    const int baseRentPrice;
    const std::string id;
    double actuallRentalPrice;
    ClientPtr actuallClient;

public:

    virtual std::string vehicleInfo();

    const int getBaseRentPrice() const;

    const std::string getId() const;

    void modifyClient(ClientPtr);

    double getActuallRentalPrice();

    virtual ~Vehicle();


    //double calculateActualRentalPrice();

    std::string vehicleClientInfo();

    Vehicle(int baseRentPrice, std::string id, ClientPtr actuallClient);
};

#endif //POBIZ01_VEHICLE_H
