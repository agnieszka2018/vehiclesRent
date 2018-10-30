//
// Created by pobi on 29.10.18.
//

#ifndef POBIZ01_VEHICLE_H
#define POBIZ01_VEHICLE_H

#include <string>

class Vehicle{
    const int baseRentPrice;
    const std::string id;
public:
    Vehicle(int price, std::string idNumber);
    //Vehicle(std::string idNumber);
    std::string vehicleInfo();

};

#endif //POBIZ01_VEHICLE_H

