//
// Created by pobi on 13.12.18.
//

#include "SearchEngine.h"

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
