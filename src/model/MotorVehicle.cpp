//
// Created by pobi on 08.11.18.
//
#include "MotorVehicle.h"
#include <iostream>


MotorVehicle::~MotorVehicle() {
    std::cout << "Destruktor MotorVehicle" << std::endl;
}

double MotorVehicle::calculateActualRentalPrice() {
    return getBaseRentPrice() * engineDisplacement;
};

const double MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

MotorVehicle::MotorVehicle(int baseRentPrice, std::string id, int engineDisplacement, double actuallRentalPrice)
        : Vehicle(baseRentPrice, id), engineDisplacement{engineDisplacement},
          actuallRentalPrice{calculateActualRentalPrice()} {
    std::cout << "Konstruktor MotorVehicle" << std::endl;
}

/*double MotorVehicle::getActuallRentalPrice() {
    return actuallRentalPrice;
}*/

