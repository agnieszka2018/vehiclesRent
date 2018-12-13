//
// Created by pobi on 08.11.18.
//
#include "Mope.h"
#include <iostream>

Mope::~Mope() {

    std::cout << "Destruktor Mope" << std::endl;
}

Mope::Mope(int baseRentPrice, std::string id, int engineDisplacement) : MotorVehicle(baseRentPrice, id,
                                                                                     engineDisplacement,
                                                                                     calculateActualRentalPrice(
                                                                                             baseRentPrice,
                                                                                             engineDisplacement)) {
    this->actuallRentalPrice = calculateActualRentalPrice(baseRentPrice, engineDisplacement);
}

double Mope::calculateActualRentalPrice(int baseRentPrice, int engineDisplacement) {

    if (engineDisplacement < 1000)
        return 1.0 * baseRentPrice;
    else if (engineDisplacement >= 1000 && engineDisplacement <= 2000)
        return baseRentPrice * (((0.5 * (engineDisplacement - 1000)) / 1000) + 1.0);
    else if (engineDisplacement > 2000)
        return baseRentPrice * 1.5;
    else
        return 0;
}


std::string Mope::vehicleInfo() {
    std::string info = "\ncena podstawowa skutera za dobę: " + std::to_string(getBaseRentPrice()) + "\n";
    info += "cena aktualna skutera za dobę: " + std::to_string(actuallRentalPrice) + "\n";
    info += "id skutera: " + getId() + "\n";
    info += "pojemność silnika w skuterze: " + std::to_string(getEngineDisplacement()) + "\n";
    return info;
}


/*double Mope::getActuallRentalPrice() {
    return actuallRentalPrice;
}*/

