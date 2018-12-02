//
// Created by pobi on 09.11.18.
//

#include "RentsRepository.h"

using namespace std;

void RentsRepository::createRent(RentPtr rent, VehicleRepoPtr repozytoriumPojazdow) {

    //sprawdzam czy pojazd jest dostepny?
    //for (Vehicle *vehicle: repozytoriumPojazdow->getVehicles()) {
    //    if (rent->getVehicle() == vehicle)
            rents.push_back(rent);
    //}

    //kasuje z repozytorium pojazdow, bo pojazd został wypożyczony
    repozytoriumPojazdow->removeVehicle(rent->getVehicle());
}

void RentsRepository::removeRent(RentPtr rent, VehicleRepoPtr repozytoriumPojazdow) {
    rents.remove(rent);
    rent->returnVehicle();

    //dodaje do repozytorium pojazow, bo pojazd został oddany
    repozytoriumPojazdow->createVehicle(rent->getVehicle());
}

string RentsRepository::rentReport() {

    string info;
    info += "lista wypozyczen: \n";

    for (RentPtr rent:rents) {
        info += rent->rentInfo() + "\n";
    }

    info += "koniec listy.\n";
    return info;
}


string RentsRepository::getClientForRentedVehicle(VehiclePtr vehicle) {
    return vehicle->vehicleClientInfo();
}
