//
// Created by pobi on 08.11.18.
//
#ifndef POBIZ01_BICYCLE_H
#define POBIZ01_BICYCLE_H

#include <string>
#include "Vehicle.h"

class Bicycle : public Vehicle {

    ClientPtr actuallClient;    //nadpisane pole z Vehicle

public:

    Bicycle(int baseRentPrice, std::string id);


    virtual ~Bicycle();
};


#endif //POBIZ01_BICYCLE_H
