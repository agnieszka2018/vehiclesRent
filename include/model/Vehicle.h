//
// Created by pobi on 29.10.18.
//

#ifndef POBIZ01_VEHICLE_H
#define POBIZ01_VEHICLE_H

#include <string>

class Vehicle {
    const int price;
    const std::string idNumber;

public:
    Vehicle(int price, std::string idNumber);

    std::string vehicleInfo();

    const int getPrice() const;

    ~Vehicle();
};

#endif //POBIZ01_VEHICLE_H
