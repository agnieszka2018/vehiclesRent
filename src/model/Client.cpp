//
// Created by pobi on 14.10.18.
//
#include <iostream>
#include <string>
#include "../../include/model/Client.h"
#include "../../include/model/Address.h"
#include "Rent.h"


/*Client::Client() {
    //firstName = "Imię";
    //lastName = "Nazwisko";
    //personalID = "111111111";

    std::cout << "konstruktor bezparametrowy jest wywolany" << std::endl;
}*/

using namespace std;

Client::Client(std::string firstName, std::string lastName, std::string personalID, Address *address,
               Address *registeredAddress, Rent *actuallRent) : firstName{firstName},
                                                                lastName{lastName},
                                                                personalID{personalID}, address{address},
                                                                registeredAddress{registeredAddress},
                                                                actuallRent{actuallRent} {

    //this->firstName = firstName;
    //this->lastName = lastName;
    //this->personalID = personalID;
    static int i = 0;
    cout << "konstruktor parametrowy nr: " << ++i << " jest wywolany" << endl << endl;
}


void Client::modifyRent(Rent *rentFromRent) {
    actuallRent = rentFromRent;
}


std::string Client::clientInfo() {

    std::string print = firstName + " " + lastName + " " + personalID;

    if (actuallRent != nullptr) {
        if (address != nullptr)
            //address = &obiekt;
            print += ", adres zamieszkania: " + address->displayInfo() + " " + actuallRent->rentInfo();
        else if (registeredAddress != nullptr)
            print += ", adres zameldowania: " + address->displayInfo() + " " + actuallRent->rentInfo();
        else
            print += " " + actuallRent->rentInfo();
    } else {
        if (address != nullptr)
            print += ", adres zamieszkania: " + address->displayInfo();
        else if (registeredAddress != nullptr)
            print += ", adres zameldowania: " + address->displayInfo();
    }


    return print;
    //return firstName + "_" + lastName + "_" + personalID + ".";
}

std::string Client::getClient(){

    std::string tekst = "imie " + firstName + " nazwisko " + lastName + " pesel " + personalID + " adres: " + address->displayInfo(); //"adres zameldowania: " + registeredAddress->displayInfo();
   return tekst;
}

Client::~Client() {
    cout << "destruktor jest wywolany" << endl;
}

Rent *Client::getActuallRent() const {
    return actuallRent;
}
