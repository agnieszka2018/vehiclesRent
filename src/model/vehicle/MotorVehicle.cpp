//
// Created by pobi on 08.11.18.
//
#include "vehicle/MotorVehicle.h"
#include <iostream>


MotorVehicle::~MotorVehicle() {}

double MotorVehicle::calculateActualRentalPrice() {
    return getBaseRentPrice() * engineDisplacement;
};

const double MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

MotorVehicle::MotorVehicle(int baseRentPrice, std::string id, int engineDisplacement, double actuallRentalPrice)
        : Vehicle(baseRentPrice, id), engineDisplacement{engineDisplacement},
          actuallRentalPrice{calculateActualRentalPrice()} {}

/*double MotorVehicle::getActuallRentalPrice() {
    return actuallRentalPrice;
}*/

