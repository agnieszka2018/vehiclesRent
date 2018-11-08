//
// Created by pobi on 08.11.18.
//
#include "Bicycle.h"
#include <iostream>


Bicycle::Bicycle(int basePrice, std::string id) : Vehicle(basePrice, id) {

    std::cout << "Konstruktor Bicycle" << std::endl;
}


Bicycle::~Bicycle() {

    std::cout << "Destruktor Bicycle" << std::endl;
}
