//
// Created by pobi on 29.10.18.
//

#include <string>
#include <iostream>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int baseRentPrice, string id, ClientPtr actuallClient) : baseRentPrice{baseRentPrice}, id{id},
                                                                        actuallClient{actuallClient} {}


const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
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

void Vehicle::modifyClient(ClientPtr client) {

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