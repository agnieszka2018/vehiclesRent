//
// Created by pobi on 20.10.18.
//
#include <iostream>
#include <string>
#include "../../include/model/Client.h"
#include "../../include/model/Address.h"

Address::Address(std::string street, std::string number) {
    this->street = street;
    this->number = number;
}

void Address::changeInfo(std::string ulica) {
    street = ulica;
    number = "numer";
}

std::string Address::displayInfo()
{
    std::string print;

    print += street +" "+ number;

    return print;
}