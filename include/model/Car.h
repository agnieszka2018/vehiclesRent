//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_CAR_H
#define POBIZ01_CAR_H

#include <string>
#include "MotorVehicle.h"

class Car : public MotorVehicle {
private:
//pola

public:
    Car(int basePrice, std::string id);

    virtual ~Car();
};


#endif //POBIZ01_CAR_H
