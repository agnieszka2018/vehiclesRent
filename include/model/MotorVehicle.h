//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOTORVEHICLE_H
#define POBIZ01_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle : public Vehicle {

    const int engineDisplacement;
    double actuallRentalPrice;

public:
    MotorVehicle(int baseRentPrice, std::string id, int engineDisplacement, double actuallRentalPrice);

    const double getEngineDisplacement() const;

    double calculateActualRentalPrice();

    virtual double getActuallRentalPrice();

    virtual ~MotorVehicle();
};


#endif //POBIZ01_MOTORVEHICLE_H
