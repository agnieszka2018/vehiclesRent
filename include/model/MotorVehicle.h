//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOTORVEHICLE_H
#define POBIZ01_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class Vehicle;

class MotorVehicle : public Vehicle {

    const int engineDisplacement;
    double actuallRentalPrice;
    ClientPtr actuallClient;    //nadpisane pole z Vehicle

public:
    MotorVehicle(int baseRentPrice, std::string id, int engineDisplacement, double actuallRentalPrice);

    const double getEngineDisplacement() const;

    double calculateActualRentalPrice();

    //double getActuallRentalPrice();

    virtual ~MotorVehicle();
};


#endif //POBIZ01_MOTORVEHICLE_H
