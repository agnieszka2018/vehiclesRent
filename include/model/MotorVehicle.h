//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOTORVEHICLE_H
#define POBIZ01_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle : public Vehicle {

    const int engineDisplacement;

public:
    MotorVehicle(int baseRentPrice, std::string id, double actuallRentalPrice, int engineDisplacement);

    const int getEngineDisplacement() const;

    virtual ~MotorVehicle();
};


#endif //POBIZ01_MOTORVEHICLE_H
