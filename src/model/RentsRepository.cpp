//
// Created by pobi on 09.11.18.
//

#include "RentsRepository.h"

using namespace std;

void RentsRepository::createRent(RentPtr rent, VehicleRepoPtr repozytoriumPojazdow) {

    //sprawdzam czy pojazd jest dostepny?
    //for (Vehicle *vehicle: repozytoriumPojazdow->getVehicles()) {
    //    if (rent->getVehicle() == vehicle)
    currentRents.push_back(rent);
    //}

    //kasuje z repozytorium pojazdow, bo pojazd został wypożyczony
    repozytoriumPojazdow->removeVehicle(rent->getVehicle());
}

void RentsRepository::removeRent(RentPtr rent, VehicleRepoPtr repozytoriumPojazdow) {
    currentRents.remove(rent);
    archiveRents.push_back(rent);
    rent->returnVehicle();

    //dodaje do repozytorium pojazow, bo pojazd został oddany
    repozytoriumPojazdow->createVehicle(rent->getVehicle());
}

string RentsRepository::rentReport() {

    string info;
    info += "lista aktualnych wypozyczen: \n";

    for (RentPtr rent:currentRents) {
        info += rent->rentInfo() + "\n";
    }

    info += "koniec listy.\n";
    return info;
}


string RentsRepository::getClientForRentedVehicle(VehiclePtr vehicle) {
    string info = (vehicle->vehicleClientInfo()) + " " + (vehicle->getActuallClient()->getAddress()->displayInfo()) + " " +
            (vehicle->getActuallClient()->getRegisteredAddress()->displayInfo());

    return info;
}

RentPtr RentsRepository::findRent(int number) {

    int liczba = 1;

    std::list<RentPtr>::iterator iter;
    for (iter = currentRents.begin(); iter != currentRents.end(); iter++) {
        if (liczba == number)
            return *iter;
        liczba++;
    }
}

RentPtr RentsRepository::operator()(int number) {

    //metoda zwraca wskaźnik do wypożyczenia o danym indeksie
    return findRent(number);
}
