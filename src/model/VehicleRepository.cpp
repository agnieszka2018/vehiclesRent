//
// Created by pobi on 11.11.18.
//

#include <string>
#include "VehicleRepository.h"

//using namespace std;

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

/*
VehiclePtr VehicleRepository::operator()(Vehicle vehicle) {

//metoda wyszukuje pojazd identyczny do zadanego
    std::list<VehiclePtr>::iterator iter;

    iter = std::find(vehicles.begin(), vehicles.end(), vehicle);
    if (iter != vehicles.end()) //gdy nie znaleziono elementu, metoda zwraca ostatni element z kontenera
        return (*iter);

    try {
        if ((*vehicles.back()) != vehicle) {
            VehicleException vehicleNotFound("Nie znaleziono pojazdu w Repozytorium Pojazdów!");
            throw vehicleNotFound;
        }
    }
    catch (VehicleException vehicleNotFound) {
        std::cout << vehicleNotFound.what();
    }

//return ???
} */

bool VehicleRepository::operator==(Vehicle vehicle2) {

    VehiclePtr vehicle3 = std::make_shared<Vehicle>(vehicle2);

    //if (std::any_of(vehicles.begin(), vehicles.end(), vehicle3))   //test if any element in range fulfills condition
    //    return true;
    //else
    return false;
}

VehicleRepository::~VehicleRepository() {
    std::cout << "Destruktor VehicleRepository" << std::endl;
}