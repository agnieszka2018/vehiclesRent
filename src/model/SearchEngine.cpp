//
// Created by pobi on 13.12.18.
//

#include "SearchEngine.h"

void SearchEngine::setName(std::string name) {
    this->name = name;
    byName = true;
}

void SearchEngine::setCarId(std::string carId) {
    this->carId = carId;
    byCarId = true;
}

bool SearchEngine::operator()(RentPtr rent) {
    bool output = true;

    if (byName) {
        if (rent->getClient()->getFirstName() == name)
            output = true;
        else
            output = false;
    }

    if (byCarId) {
        if (rent->getVehicle()->getId() == carId)
            output = true;
        else
            output = false;
    }

    return output;
}