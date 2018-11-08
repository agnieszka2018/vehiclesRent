//
// Created by pobi on 08.11.18.
//
#include "Bicycle.h"
#include <iostream>


Bicycle::~Bicycle() {

    std::cout << "Destruktor Bicycle" << std::endl;
}

Bicycle::Bicycle(const int baseRentPrice, const std::string &id, const double actuallRentalPrice) : Vehicle(
        baseRentPrice, id, baseRentPrice) {}


