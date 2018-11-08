//
// Created by pobi on 08.11.18.
//
#include "Mope.h"
#include <iostream>


Mope::~Mope() {

    std::cout << "Destruktor Mope" << std::endl;
}

Mope::Mope(const int baseRentPrice, const std::string &id, int engineDisplacement)
        : MotorVehicle(baseRentPrice, id, calculateActualRentalPrice(baseRentPrice, engineDisplacement),
                       engineDisplacement) {
}

double Mope::calculateActualRentalPrice(int baseRentPrice, int engineDisplacement) {

    if (engineDisplacement < 1000) return 1.0 * baseRentPrice;
    else if (engineDisplacement >= 1000 && engineDisplacement <= 2000) return baseRentPrice * ((1.0 *
                                                                                                ((engineDisplacement -
                                                                                                  1000) / 2) / 1000) +
                                                                                               1);
    else if (engineDisplacement > 2000) return baseRentPrice * 1.5;
    else return 0;

}

