//
// Created by pobi on 08.11.18.
//

#include "vehicle/Bicycle.h"
#include <iostream>

Bicycle::~Bicycle() {}

Bicycle::Bicycle(int baseRentPrice, std::string id) : Vehicle(baseRentPrice, id) {}

