//
// Created by pobi on 14.10.18.
//
#include <iostream>
#include <string>
#include "../../include/model/Client.h"
#include "../../include/model/Address.h"


Client::Client() {
    // firstName = "Zofia";
    // lastName = "Kochanowska";
    // personalID = "111111111";

    std::cout << "konstruktor bezparametrowy jest wywolany" << std::endl;
}

Client::Client(std::string firstName, std::string lastName, std::string personalID) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->personalID = personalID;

    std::cout << "konstruktor prametrowy jest wywolany" << std::endl;
}

Client::~Client() {
    std::cout << "destruktor jest wywolany" << std::endl;
}

std::string Client::clientInfo() {
    return firstName + "_" + lastName + "_" + personalID + ".";
}