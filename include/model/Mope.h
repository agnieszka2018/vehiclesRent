//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOPE_H
#define POBIZ01_MOPE_H

#include <string>
#include "MotorVehicle.h"

class Mope : public MotorVehicle {

    double actuallRentalPrice;

public:

    double calculateActualRentalPrice(int baseRentPrice, int engineDisplacement); //a nie override?

    Mope(int baseRentPrice, std::string id, int engineDisplacement);

    std::string vehicleInfo() override;

    virtual ~Mope();
};


#endif //POBIZ01_MOPE_H
