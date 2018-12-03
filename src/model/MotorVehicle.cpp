//
// Created by pobi on 08.11.18.
//
#include "MotorVehicle.h"
#include <iostream>


/*MotorVehicle::MotorVehicle(int engineDisplacement) : engineDisplacement(engineDisplacement), Vehicle(baseRentPrice, id) {

    std::cout << "Konstruktor MotorVehicle" << std::endl;
}*/


MotorVehicle::~MotorVehicle() {

    std::cout << "Destruktor MotorVehicle" << std::endl;
}

double MotorVehicle::calculateActualRentalPrice() {
    return getBaseRentPrice() * engineDisplacement;
};

const double MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}


/*double MotorVehicle::getActuallRentalPrice() {
    return actuallRentalPrice;
}*/

MotorVehicle::MotorVehicle(int baseRentPrice, std::string id, int engineDisplacement, double actuallRentalPrice)
        : Vehicle(baseRentPrice, id, actuallClient), engineDisplacement{engineDisplacement}, actuallRentalPrice{calculateActualRentalPrice()} {}


