//
// Created by pobi on 14.10.18.
//
#include <iostream>
#include <string>
#include "../../include/model/Client.h"
#include "../../include/model/Address.h"


Client::Client() {
    std::cout << "konstruktor bezparametrowy" << std::endl;
}

Client::Client(std::string firstName, std::string lastName, std::string personalID) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->personalID = personalID;

    std::cout << "konstruktor prametrowy" << std::endl;
}

Client::~Client() {
    std::cout << "destruktor" << std::endl;
}

std::string Client::clientInfo() {
    return firstName + " " + lastName + " " + personalID;
}