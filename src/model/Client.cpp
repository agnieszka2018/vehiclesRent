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
               Address *registeredAddress, ClientType *clientType) : firstName{firstName},
                                                                     lastName{lastName},
                                                                     personalID{personalID},
                                                                     address{address},
                                                                     registeredAddress{registeredAddress},
                                                                     clientType{clientType} {
    static int i = 0;
    cout << "konstruktor parametrowy nr: " << ++i << " jest wywolany" << endl << endl;
}


void Client::addRent(Rent *rentFromRent) {
    clientActuallRents.push_back(rentFromRent); //dodaje wypożyczenie do listy wypożyczeń klienta
}

void Client::deleteRent(Rent *rentFromRent) {
    vector<Rent *>::iterator it;
    for (it = clientActuallRents.begin(); it != clientActuallRents.end(); ++it) {
        if (rentFromRent == *it)
            clientActuallRents.erase(it); //usuwa wypożyczenie z listy wypożyczeń klienta
    }

    allClientRents.push_back(rentFromRent); //dodaje wypożyczenie do listy wszystkich zakończonych wypożyczeń (discount)
}

std::string Client::clientName() {
    std::string print = firstName + " " + lastName + " " + personalID + "\n";
    return print;
}


std::string Client::clientInfo() {

    std::string print = firstName + " " + lastName + " " + personalID + "\n";

    if (address != nullptr) print += "adres zamieszkania: " + address->displayInfo();
    if (registeredAddress != nullptr) print += "adres zameldowania: " + address->displayInfo();

    if (!clientActuallRents.empty()) {
        vector<Rent *>::iterator it;
        for (it = clientActuallRents.begin(); it != clientActuallRents.end(); ++it) {
            print += (*it)->rentInfoFromClient();
        }
    }

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


std::vector<Rent *> Client::getClientActuallRents() {

    return clientActuallRents;
}

void Client::setClientType(ClientType *clientType) {
    this->clientType = clientType;
}

ClientType * Client::getClientType() {
    return clientType;
}

Client::~Client() {
    cout << "destruktor client jest wywolany" << endl;
    vector<Rent *>::iterator it;
    for (it = clientActuallRents.begin(); it != clientActuallRents.end(); ++it) { delete *it; }
}