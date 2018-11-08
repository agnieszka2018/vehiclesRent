//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_MOPE_H
#define POBIZ01_MOPE_H

#include <string>
#include "MotorVehicle.h"

class Mope : public MotorVehicle {
private:
//pola

public:
    Mope(int basePrice, std::string id);

    virtual ~Mope();
};


#endif //POBIZ01_MOPE_H
