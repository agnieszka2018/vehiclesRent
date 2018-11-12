//
// Created by pobi on 29.10.18.
//

#ifndef POBIZ01_VEHICLE_H
#define POBIZ01_VEHICLE_H

#include <string>

class Client;

class Vehicle{

    const int baseRentPrice;
    const std::string id;
    double actuallRentalPrice;
    Client *actuallClient  = nullptr;

public:

    Vehicle(int baseRentPrice, std::string id, Client *actuallClient = nullptr);

    virtual std::string vehicleInfo();

    const int getBaseRentPrice() const;

    const std::string &getId() const;

    void modifyClient(Client *);

    double getActuallRentalPrice();

    virtual ~Vehicle();


    //double calculateActualRentalPrice();

    std::string vehicleClientInfo();

};

#endif //POBIZ01_VEHICLE_H


