//
// Created by pobi on 14.10.18.
//
#include <iostream>
#include <string>
#include <model/Client.h>

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
    //cout<<"actrent: "<<actuallRent;
    actuallRent = rentFromRent;
    //cout<<"actrent: "<<actuallRent;
}

std::string Client::clientName() {
    std::string print = firstName + " " + lastName + " " + personalID + "\n";
    return print;
}


std::string Client::clientInfo() {

    std::string print = firstName + " " + lastName + " " + personalID + "\n";

    /*if (&actuallRent != nullptr) { //czy jest wypozyczenie
        if (address != nullptr) //czy jest adres
            //address = &obiekt;
            print += "adres zamieszkania: " + address->displayInfo();// + " " + actuallRent->rentInfoFromClient();
        else if (registeredAddress != nullptr) //
            print += "adres zameldowania: " + address->displayInfo();// + " " + actuallRent->rentInfoFromClient();
        else
            print += " " + actuallRent->rentInfoFromClient();
    } else {
        if (address != nullptr)
            print += "adres zamieszkania: " + address->displayInfo();
        else if (registeredAddress != nullptr)
            print += "adres zameldowania: " + address->displayInfo();
    }*/
    if(address != nullptr) print += "adres zamieszkania: " + address->displayInfo();
    if(registeredAddress != nullptr) print += "adres zameldowania: " + address->displayInfo();
    if(actuallRent != nullptr) print += actuallRent->rentInfoFromClient();


    return print;
    //return firstName + "_" + lastName + "_" + personalID + ".";
}


Client::~Client() {
    cout << "destruktor jest wywolany" << endl;
}

Rent *Client::getActuallRent() const {
    return actuallRent;
}


