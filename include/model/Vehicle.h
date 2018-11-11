//
// Created by pobi on 29.10.18.
//

#ifndef POBIZ01_VEHICLE_H
#define POBIZ01_VEHICLE_H

#include <string>

class Vehicle{

    const int baseRentPrice;
    const std::string id;
    double actuallRentalPrice;

public:

    Vehicle(int baseRentPrice, std::string &id, double actuallRentalPrice);

    std::string vehicleInfo();

    const int getBaseRentPrice() const;

    virtual ~Vehicle();

    double getActuallRentalPrice();

    double calculateActualRentalPrice();

};

#endif //POBIZ01_VEHICLE_H


