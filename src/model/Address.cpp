//
// Created by pobi on 20.10.18.
//

#include "Address.h"

Address::Address(std::string street, std::string number) {
    this->street = street;
    this->number = number;
}

void Address::setAddress(std::string ulica, std::string numer) {
    street = ulica;
    number = numer;
}

std::string Address::displayInfo() {
    std::string print;

    print += street + " " + number;

    return print;
}