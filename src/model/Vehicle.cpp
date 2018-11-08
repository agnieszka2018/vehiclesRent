//
// Created by pobi on 29.10.18.
//
#include <../../include/model/Vehicle.h>
#include <string>
#include <iostream>

using namespace std;

Vehicle::Vehicle(int baseRentPrice, string id) : baseRentPrice{baseRentPrice}, id{id} {
    cout << "Konstruktor Vehicle" << endl;
}

string Vehicle::vehicleInfo() {
    string info = "\ncena podstawowa: " + to_string(baseRentPrice) + "\nid: " + id + "\n";
    return info;
}

const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
}

Vehicle::~Vehicle() {
    cout << "Destruktor Vehicle" << endl;
}
