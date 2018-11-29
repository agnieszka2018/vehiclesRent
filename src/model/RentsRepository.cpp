//
// Created by pobi on 09.11.18.
//

#include <model/RentsRepository.h>
#include "Vehicle.h"
#include "Rent.h"
#include "RentsRepository.h"
#include "VehicleRepository.h"

using namespace std;

void currentRentsRepository::createRent(Rent *rent, VehicleRepository *repozytoriumPojazdow) {

    //sprawdzam czy pojazd jest dostepny?
    for (Vehicle *vehicle: repozytoriumPojazdow->getVehicles()) {
        if (rent->getVehicle() == vehicle)
            rents.push_back(rent);
    }

    //kasuje z repozytorium pojazdow, bo pojazd został wypożyczony
    repozytoriumPojazdow->removeVehicle(rent->getVehicle());
}

void currentRentsRepository::removeRent(Rent *rent, VehicleRepository *repozytoriumPojazdow) {
    rents.remove(rent);
    rent->returnVehicle();

    //dodaje do repozytorium pojazow, bo pojazd został oddany
    repozytoriumPojazdow->createVehicle(rent->getVehicle());
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
