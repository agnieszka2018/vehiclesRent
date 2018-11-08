//
// Created by pobi on 08.11.18.
//
#include "MotorVehicle.h"
#include <iostream>


MotorVehicle::MotorVehicle(int basePrice, std::string id) : Vehicle(basePrice, id) {

    std::cout << "Konstruktor MotorVehicle" << std::endl;
}


MotorVehicle::~MotorVehicle() {

    std::cout << "Destruktor MotorVehicle" << std::endl;
}