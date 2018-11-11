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

const int MotorVehicle::getEngineDisplacement() const {
    return engineDisplacement;
}

MotorVehicle::MotorVehicle(int baseRentPrice, std::string id, double actuallRentalPrice, int engineDisplacement)
        : Vehicle(baseRentPrice, id, actuallRentalPrice), engineDisplacement{engineDisplacement} {}

