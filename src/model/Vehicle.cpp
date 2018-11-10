//
// Created by pobi on 29.10.18.
//
#include <../../include/model/Vehicle.h>
#include <Car.h>
#include <string>
#include <iostream>
#include <model/Vehicle.h>


using namespace std;



string Vehicle::vehicleInfo() {
    string info = "\ncena podstawowa: " + to_string(baseRentPrice) + "\n";
    info += "cena wlasciwa: " + to_string(actuallRentalPrice) + "\n";
    info += "id: " + id + "\n";
    return info;
}

const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
}

const double Vehicle::getActuallRentalPrice() const {
    return actuallRentalPrice;
}


Vehicle::~Vehicle() {
    cout << "Destruktor Vehicle" << endl;
}

Vehicle::Vehicle(const int baseRentPrice, const string &id, const double actuallRentalPrice) : baseRentPrice(
        baseRentPrice), id(id), actuallRentalPrice(actuallRentalPrice) {}

