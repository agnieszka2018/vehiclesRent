//
// Created by pobi on 08.11.18.
//
#include "Car.h"
#include <iostream>


Car::Car(int basePrice, std::string id) : MotorVehicle(basePrice, id) {

    std::cout << "Konstruktor Car" << std::endl;
}


Car::~Car() {

    std::cout << "Destruktor Car" << std::endl;
}
