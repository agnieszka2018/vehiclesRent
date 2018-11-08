//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOPE_H
#define POBIZ01_MOPE_H

#include <string>
#include "MotorVehicle.h"

class Mope : public MotorVehicle {
private:

    double calculateActualRentalPrice(int baseRentPrice, int engineDisplacement);

public:

    Mope(const int baseRentPrice, const std::string &id, int engineDisplacement);

    virtual ~Mope();
};


#endif //POBIZ01_MOPE_H
