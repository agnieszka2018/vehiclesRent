//
// Created by pobi on 14.10.18.
//
#include <iostream>
#include <string>
#include "Client.h"

using namespace std;

Client::Client(std::string firstName, std::string lastName, std::string personalID, ClientTypePtr clientType,
               AddressPtr address, AddressPtr registeredAddress) :
        firstName{firstName}, lastName{lastName}, personalID{personalID}, clientType{clientType}, address{address},
        registeredAddress{registeredAddress} {
    static int i = 0;
    cout << "konstruktor parametrowy nr: " << ++i << " jest wywolany" << endl << endl;
}


void Client::addRent(RentPtr rentFromRent) {
    clientActuallRents.push_back(rentFromRent); //dodaje wypożyczenie do listy wypożyczeń klienta
}

void Client::deleteRent(RentPtr rentFromRent) {

    //obsługa wyjątku - sprawdzam czy klient ma aktualnie przynajmniej jedno wypożyczenie
    try {
        if (clientActuallRents.size() < 1) {
            ClientException brakWypozyczen("Klient aktualnie nie posiada wypożyczeń!");
            throw brakWypozyczen;
        }
    }
    catch (ClientException brakWypoz) {
        std::cout << brakWypoz.what();
    }


    vector<RentPtr>::iterator it;
    for (it = clientActuallRents.begin(); it != clientActuallRents.end(); it++) {
        if (rentFromRent == *it)
            clientActuallRents.erase(it); //usuwa wypożyczenie z listy wypożyczeń klienta
    }

    allClientRents.push_back(rentFromRent); //dodaje wypożyczenie do listy wszystkich zakończonych wypożyczeń
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
        vector<RentPtr>::iterator it;
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


std::vector<RentPtr> Client::getClientActuallRents() {

    return clientActuallRents;
}

void Client::setClientType(ClientTypePtr clientType) {
    this->clientType = clientType;
}

ClientTypePtr Client::getClientType() {
    return clientType;
}

vector<RentPtr> Client::getAllClientRents() {
    return allClientRents;
}

double Client::calculatePriceWithDiscount(RentPtr rent) {
    double cost = rent->getCost();
    double discount = clientType->getClientTypeDiscount();

    return cost - (cost * discount);
}

bool Client::operator==(Client client2) {
    if (((this->clientName()) == (client2.clientName())) &&
        ((this->clientType) == (client2.clientType)) && ((this->address) == (client2.address)) &&
        ((this->registeredAddress) == (client2.registeredAddress)))
        return true;
    else
        return false;
}

Client::~Client() {
    cout << "destruktor client jest wywolany" << endl;
}

AddressPtr Client::getAddress() {
    return address;
}

AddressPtr Client::getRegisteredAddress() {
    return registeredAddress;
}

