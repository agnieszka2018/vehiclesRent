//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOTORVEHICLE_H
#define POBIZ01_MOTORVEHICLE_H

#include <string>
#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
//pola

public:
    MotorVehicle(int basePrice, std::string id);

    virtual ~MotorVehicle();
};


#endif //POBIZ01_MOTORVEHICLE_H
