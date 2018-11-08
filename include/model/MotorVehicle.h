//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOTORVEHICLE_H
#define POBIZ01_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    int engineDisplacement;
public:
    MotorVehicle(const int baseRentPrice, const std::string &id, const double actuallRentalPrice,
                 int engineDisplacement);

    int getEngineDisplacement() const;

    virtual ~MotorVehicle();
};


#endif //POBIZ01_MOTORVEHICLE_H
