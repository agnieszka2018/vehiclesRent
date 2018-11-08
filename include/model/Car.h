//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_CAR_H
#define POBIZ01_CAR_H

#include <string>
#include "MotorVehicle.h"

class Car : public MotorVehicle {
private:
    std::string segment;

    double calculateActualRentalPrice(int baseRentPrice, int engineDisplacement, std::string segment);

public:
    Car(const int baseRentPrice, const std::string &id, int engineDisplacement,
        const std::string &segment);

    const std::string &getSegment() const;

    virtual ~Car();
};


#endif //POBIZ01_CAR_H
