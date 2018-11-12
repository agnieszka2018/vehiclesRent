//
// Created by pobi on 11.11.18.
//

#include <string>
#include "VehicleRepository.h"
//using namespace std;

void VehicleRepository::createVehicle(Vehicle *vehicle) {

    vehicles.push_back(vehicle);
    //vehicles.push_front(vehicle);
}

void VehicleRepository::removeVehicle(Vehicle *vehicle) {

    vehicles.remove(vehicle);
}


std::string VehicleRepository::vehicleReport() {

    long value = vehicles.size();

    std::string info = "Liczba pojazdów  w repozytorium: " + std::to_string(value);

    for (Vehicle *vehicle: vehicles) {
        info += vehicle->vehicleInfo() + "\n";
    }

    info += "To był ostatni pojazd w repozytorium.";

    return info;
}