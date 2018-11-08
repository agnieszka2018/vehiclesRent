//
// Created by pobi on 08.11.18.
//
#include "Mope.h"
#include <iostream>


Mope::Mope(int basePrice, std::string id) : MotorVehicle(basePrice, id) {

    std::cout << "Konstruktor Mope" << std::endl;
}


Mope::~Mope() {

    std::cout << "Destruktor Mope" << std::endl;
}
