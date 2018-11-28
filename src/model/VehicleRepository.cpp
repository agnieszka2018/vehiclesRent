//
// Created by pobi on 11.11.18.
//

#include <string>
#include "VehicleRepository.h"
#include "Vehicle.h"
//using namespace std;

void VehicleRepository::createVehicle(Vehicle *vehicle) {

    vehicles.push_back(vehicle);
}

void VehicleRepository::removeVehicle(Vehicle *vehicle) {

    vehicles.remove(vehicle);
}


std::string VehicleRepository::vehicleReport() {

    long value = vehicles.size();

    std::string info = "Liczba pojazdów  w repozytorium: " + std::to_string(value) + "\n\n";

    int i = 0;

    for (Vehicle *vehicle: vehicles) {
        ++i;
        info += "pojazd nr:" + std::to_string(i) + " " + vehicle->vehicleInfo() + "\n";
    }

    info += "To był ostatni pojazd w repozytorium. \n";

    return info;
}

std::list<Vehicle *> VehicleRepository::getVehicles() {
    return vehicles;
}

Vehicle *VehicleRepository::findVehicle(int number) {

    int liczba = 1;

    std::list<Vehicle *>::iterator iter;
    for (iter = vehicles.begin(); iter != vehicles.end(); iter++) {
        //znaleźć odpowiedni indeks o numerze number
        if (liczba == number)
            return *iter;
        liczba++;
    }
}

VehicleRepository::~VehicleRepository() {
    std::cout<<"Destruktor VehicleRepository"<<std::endl;
}
