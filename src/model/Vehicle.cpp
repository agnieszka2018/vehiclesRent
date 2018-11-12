//
// Created by pobi on 29.10.18.
//
#include "Car.h"
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Client.h"

using namespace std;

Vehicle::Vehicle(int baseRentPrice, string id, Client *actuallClient) : baseRentPrice{baseRentPrice}, id{id},
                                                                         actuallClient{actuallClient} {}


const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
}

const double Vehicle::getActuallRentalPrice() const {
    return actuallRentalPrice;
}


Vehicle::~Vehicle() {
    cout << "Destruktor Vehicle" << endl;
}

/*double Vehicle::calculateActualRentalPrice() {
    return baseRentPrice;
};
*/

double Vehicle::getActuallRentalPrice() {
    return actuallRentalPrice;
}

void Vehicle::modifyClient(Client *client) {

    actuallClient = client;
}


string Vehicle::vehicleInfo() {
    string info = "\nCena podstawowa pojazdu za dobę: " + to_string(baseRentPrice) + "\n";
    //info += "Cena aktualna pojazdu za dobę: " + to_string(actuallRentalPrice) + "\n";
    info += "Id pojazdu: " + id + "\n";
    return info;
}

string Vehicle::vehicleClientInfo() {
    string info;
    if (actuallClient != nullptr)
        info += "klient: " + actuallClient->clientName();         //dopisac adress!!!

    return info;
}

const string Vehicle::getId() const {
    return id;
}

