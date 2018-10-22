//
// Created by pobi on 14.10.18.
//
#include <iostream>
#include <string>
#include "../../include/model/Client.h"
#include "../../include/model/Address.h"


/*Client::Client() {
    //firstName = "Imię";
    //lastName = "Nazwisko";
    //personalID = "111111111";

    std::cout << "konstruktor bezparametrowy jest wywolany" << std::endl;
}*/

using namespace std;

Client::Client(std::string firstName, std::string lastName, std::string personalID, Address *address,
               Address *registeredAddress) : firstName{firstName},
                                             lastName{lastName},
                                             personalID{personalID}, address{address},
                                             registeredAddress{registeredAddress} {

    //this->firstName = firstName;
    //this->lastName = lastName;
    //this->personalID = personalID;
    static int i = 0;
    cout << "konstruktor parametrowy nr: " << ++i << " jest wywolany" << endl;
}


Client::~Client() {
    cout << "destruktor jest wywolany" << endl;
}


std::string Client::clientInfo() {

    std::string print = firstName + " " + lastName + " " + personalID;

    if (address != nullptr)
        //address = &obiekt;
        print += ", adres zamieszkania: " + address->displayInfo();
    else if (registeredAddress != nullptr)
        print += ", adres zameldowania: " + address->displayInfo();

    return print;
    //return firstName + "_" + lastName + "_" + personalID + ".";
}

