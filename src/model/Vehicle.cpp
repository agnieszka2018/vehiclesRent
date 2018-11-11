//
// Created by pobi on 29.10.18.
//
#include "Car.h"
#include <string>
#include <iostream>
#include "Vehicle.h"

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

double Vehicle::getActuallRentalPrice() {
    return actuallRentalPrice;
}

Vehicle::~Vehicle() {
    cout << "Destruktor Vehicle" << endl;
}

double Vehicle::calculateActualRentalPrice(){
    return baseRentPrice;
};

Vehicle::Vehicle(int baseRentPrice, string &id, double actuallRentalPrice) : baseRentPrice{baseRentPrice}, id{id}, actuallRentalPrice {calculateActualRentalPrice()} {}
