//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_CAR_H
#define POBIZ01_CAR_H

#include <string>
#include "MotorVehicle.h"

class Car : public MotorVehicle {

    const std::string segment;
    double actuallRentalPrice;

public:

    double calculateActualRentalPrice(int baseRentPrice, int engineDisplacement, std::string segment);

    //double getActuallRentalPrice();

    Car(std::string segment, int baseRentPrice, std::string id, int engineDisplacement);

    const std::string &getSegment() const;

    std::string vehicleInfo() override;

    virtual ~Car();
};


#endif //POBIZ01_CAR_H
