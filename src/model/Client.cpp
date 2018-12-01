//
// Created by pobi on 14.10.18.
//
#include <iostream>
#include <string>
#include <model/Client.h>

#include "../../include/model/Client.h"
#include "../../include/model/Address.h"
#include "Rent.h"

using namespace std;

Client::Client(std::string firstName, std::string lastName, std::string personalID, Address *address,
               Address *registeredAddress, Rent *actuallRent, ClientType *clientType) : firstName{firstName},
                                                                                        lastName{lastName},
                                                                                        personalID{personalID},
                                                                                        address{address},
                                                                                        registeredAddress{
                                                                                                registeredAddress},
                                                                                        actuallRent{actuallRent},
                                                                                        clientType{clientType} {
    static int i = 0;
    cout << "konstruktor parametrowy nr: " << ++i << " jest wywolany" << endl << endl;
}


void Client::modifyRent(Rent *rentFromRent) {
    actuallRent = rentFromRent;
}

std::string Client::clientName() {
    std::string print = firstName + " " + lastName + " " + personalID + "\n";
    return print;
}


std::string Client::clientInfo() {

    std::string print = firstName + " " + lastName + " " + personalID + "\n";

    if (address != nullptr) print += "adres zamieszkania: " + address->displayInfo();
    if (registeredAddress != nullptr) print += "adres zameldowania: " + address->displayInfo();
    if (actuallRent != nullptr) print += actuallRent->rentInfoFromClient();
    if (clientType != nullptr) {
        print += "\nTyp klienta: ";
        print += clientType->getTypeName();
        print += "\nRabat: ";
        print += to_string(clientType->getClientTypeDiscount());
        print += "\nMaksymalna ilosc aut: ";
        print += to_string(clientType->getMaxRentedCarAmount());
    }

    return print;
}


Client::~Client() {
    cout << "destruktor client jest wywolany" << endl;
}

Rent *Client::getActuallRent() const {
    return actuallRent;
}

void Client::setClientType(ClientType *clientType) {
    this->clientType = clientType;
}


