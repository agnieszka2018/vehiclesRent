//
// Created by pobi on 29.10.18.
//
#include <../../include/model/Vehicle.h>
#include <iostream>
#include <string>

using namespace std;

Vehicle::Vehicle(int price, std::string idNumber) : price{price}, idNumber{idNumber} {


    cout << "konstruktor Vehicle" << std::endl;
}

Vehicle::~Vehicle() {

    std::cout << "destruktor Vehicle" << std::endl;
}

std::string Vehicle::vehicleInfo() {
    std::string info;

    info += "\ncena wynosi: " + to_string(price) + " " + "\nnumer rejestracyjny" + idNumber + "\n";

    return info;
}

const int Vehicle::getPrice() const{
    return price;
}