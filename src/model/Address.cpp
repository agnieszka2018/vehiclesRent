//
// Created by pobi on 20.10.18.
//

#include "Address.h"

Address::Address(std::string street, std::string number) {
    this->street = street;
    this->number = number;
}

void Address::setAddress(std::string streetNew, std::string numberNew) {
    street = streetNew;
    number = numberNew;
}

std::string Address::displayInfo() {
    std::string print;

    print += street + " " + number;

    return print;
}

std::string Address::getStreet() {
    return street;
}

std::string Address::getNumber() {
    return number;
}