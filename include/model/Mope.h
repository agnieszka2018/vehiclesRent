//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOPE_H
#define POBIZ01_MOPE_H

#include <string>
#include "MotorVehicle.h"

class Mope : public MotorVehicle {

public:

    double calculateActualRentalPrice(int baseRentPrice, int engineDisplacement);

    Mope(int baseRentPrice, std::string id, int engineDisplacement);

    virtual ~Mope();
};


#endif //POBIZ01_MOPE_H
