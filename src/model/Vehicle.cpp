//
// Created by pobi on 29.10.18.
//
#include "Car.h"
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Client.h"

using namespace std;

Vehicle::Vehicle(int baseRentPrice, string &id, double actuallRentalPrice, Client *actuallClient) : baseRentPrice{
        baseRentPrice}, id{id}, actuallRentalPrice{calculateActualRentalPrice()}, actuallClient{actuallClient} {}


const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
}

double Vehicle::getActuallRentalPrice() {
    return actuallRentalPrice;
}

Vehicle::~Vehicle() {
    cout << "Destruktor Vehicle" << endl;
}

double Vehicle::calculateActualRentalPrice() {
    return baseRentPrice;
};

void Vehicle::modifyClient(Client *client) {

    actuallClient = client;
}


string Vehicle::vehicleInfo() {
    string info = "\ncena podstawowa pojazdu: " + to_string(baseRentPrice) + "\n";
    info += "cena wlasciwa pojazdu: " + to_string(actuallRentalPrice) + "\n";
    info += "id pojazdu: " + id + "\n";
    return info;
}

string Vehicle::vehicleClientInfo() {
    string info;
    if (actuallClient != nullptr)
        info += "klient: " + actuallClient->clientName();         //dopisac adress!!!

    return info;
}