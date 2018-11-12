//
// Created by pobi on 09.11.18.
//

#include <model/CurrentRentsRepository.h>
#include "Vehicle.h"
#include "Rent.h"
#include "CurrentRentsRepository.h"

using namespace std;

void currentRentsRepository::createRent(Rent *rent) {
    rents.push_back(rent);
}

void currentRentsRepository::removeRent(Rent *rent) {
    rents.remove(rent);
    rent->returnVehicle();
}

string currentRentsRepository::rentReport() {

    string info;
    info += "lista wypozyczen: \n";

    for (Rent *rent:rents) {
        info += rent->rentInfo() + "\n";
    }

    info += "koniec listy.\n";
    return info;
}


string currentRentsRepository::getClientForRentedVehicle(Vehicle *vehicle) {
    return vehicle->vehicleClientInfo();
}