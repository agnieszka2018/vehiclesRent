//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include "./include/model/Client.h"
#include "./include/model/Address.h"


using namespace std;

int main() {

    //Client klient_1; bezparametrowy
    Address *aktualny_zam = new Address("Mickiewicza", "7");
    Client klient_2("Jan", "Kowalski", "123456789", aktualny_zam);

    //cout << "Klient_1 stworzony przez kostruktor bezparametrowy:" << klient_1.clientInfo() << endl;
    cout << "Klient_2 stworzony przez konstruktor parametrowy: " << klient_2.clientInfo() << endl << endl;

    // klient_1.firstName = "Zofia";


    cout << "Adres  zamieszkania przed zmianą: " << klient_2.clientInfo();

    //Client klient_3("Zenon", "Machalski", "456789123", aktualny_zam);
    //Client klient_4("Karol", "Fornalski", "891234567", aktualny_zam);
    //
    //cout << "Klient_3 stworzony przez konstruktor parametrowy: " << klient_3.clientInfo() << endl;
    //cout << "Klient_4 stworzony przez konstruktor parametrowy: " << klient_4.clientInfo() << endl;

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //aktualny_zam->street = "Sienkiewicza";
    //aktualny_zam->number = "1";
    aktualny_zam->changeInfo("promienna");
    cout << "\nAdres  zamieszkania po zmianie: " << klient_2.clientInfo();

    klient_2.clientInfo();
}