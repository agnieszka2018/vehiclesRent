//
// Created by pobi on 11.11.18.
//

#include <string>
#include "VehicleRepository.h"


void VehicleRepository::createVehicle(VehiclePtr vehicle) {

    vehicles.push_back(vehicle);
}

void VehicleRepository::removeVehicle(VehiclePtr vehicle) {

    vehicles.remove(vehicle);
}


std::string VehicleRepository::vehicleReport() {

    long value = vehicles.size();

    std::string info = "Liczba pojazdów  w repozytorium: " + std::to_string(value) + "\n\n";

    int i = 0;

    for (VehiclePtr vehicle: vehicles) {
        ++i;
        info += "pojazd nr:" + std::to_string(i) + " " + vehicle->vehicleInfo() + "\n";
    }

    info += "To był ostatni pojazd w repozytorium. \n";

    return info;
}

std::list<VehiclePtr> VehicleRepository::getVehicles() {
    return vehicles;
}

VehiclePtr VehicleRepository::findVehicle(int number) {

    int liczba = 1;

    std::list<VehiclePtr>::iterator iter;
    for (iter = vehicles.begin(); iter != vehicles.end(); iter++) {
        //znaleźć odpowiedni indeks o numerze number
        if (liczba == number)
            return *iter;
        liczba++;
    }
}

VehiclePtr VehicleRepository::operator()(int number) {

    //metoda zwraca wskaźnik do pojazdu o danym indeksie
    return findVehicle(number);
}

VehicleRepository::~VehicleRepository() {}