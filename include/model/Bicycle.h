//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_BICYCLE_H
#define POBIZ01_BICYCLE_H

#include <string>
#include "Vehicle.h"

class Bicycle : public Vehicle {
private:
//pola

public:


    Bicycle(const int baseRentPrice, const std::string &id, const double actuallRentalPrice);

    virtual ~Bicycle();
};


#endif //POBIZ01_BICYCLE_H
