//
// Created by pobi on 29.10.18.
//

#ifndef POBIZ01_VEHICLE_H
#define POBIZ01_VEHICLE_H

#include <string>

class Vehicle{
    const int baseRentPrice;
    const std::string id;
    const double actuallRentalPrice;
public:


    Vehicle(const int baseRentPrice, const std::string &id, const double actuallRentalPrice);

    std::string vehicleInfo();

    const int getBaseRentPrice() const;

    virtual ~Vehicle();

    void setActuallRentalPrice(int engineDisplacement, std::string segment);

    const double getActuallRentalPrice() const;

};

#endif //POBIZ01_VEHICLE_H

