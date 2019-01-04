//
// Created by pobi on 29.10.18.
//

#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int baseRentPrice, string id) : baseRentPrice{baseRentPrice}, id{id} {

    //obsługa wyjątku (VehicleException) - cena bazowa wypożyczenia nie może być ujemna
    if (baseRentPrice < 0) {
        throw VehicleException("Bazowa cena nie może być ujemna!\n");
    }
}


const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
}

Vehicle::~Vehicle() {}

/*double Vehicle::calculateActualRentalPrice() {
    return baseRentPrice;
};
*/

double Vehicle::getActuallRentalPrice() {
    return actuallRentalPrice;
}

void Vehicle::modifyClient(ClientPtr client) {

    actuallClient = client;
}


string Vehicle::vehicleInfo() {
    string info = "\nCena podstawowa pojazdu za dobę: " + to_string(baseRentPrice) + "\n";
    info += "Cena aktualna pojazdu za dobę: " + to_string(actuallRentalPrice) + "\n";
    info += "Id pojazdu: " + id + "\n";
    return info;
}

string Vehicle::vehicleClientInfo() {
    string info;

    if (actuallClient != nullptr)
        info += "klient: " + actuallClient->getFirstName() + " " + actuallClient->getLastName();
    if (actuallClient->getAddress() != nullptr)
        info += " " + actuallClient->getAddress()->getStreet() + " " +
                actuallClient->getAddress()->getNumber();
    if (actuallClient->getRegisteredAddress() != nullptr)
        info += " " + actuallClient->getRegisteredAddress()->getStreet() + " " +
                actuallClient->getRegisteredAddress()->getNumber();
    return info;
}

const string Vehicle::getId() const {
    return id;
}

bool Vehicle::operator==(Vehicle &vehicle2) {

    //sprawdzam czy dwa obiekty są sobie równe
    if (((this->id) == (vehicle2.id)) &&
        ((this->baseRentPrice) == (vehicle2.baseRentPrice))
        && ((this->actuallRentalPrice) == (vehicle2.actuallRentalPrice)))
        return true;
    else
        return false;
}

ClientPtr Vehicle::getActuallClient() {
    return actuallClient;
}
