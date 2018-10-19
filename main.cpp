//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include "./include/model/Client.h"


using namespace std;

int main() {

    //Client klient_1;
    Client klient_2("Jan", "Kowalski", "123456789");

    //cout << "Klient_1 stworzony przez kostruktor bezparametrowy:" << klient_1.clientInfo() << endl;
    cout << "Klient_2 stworzony przez konstruktor parametrowy:" << klient_2.clientInfo() << endl;

    // klient_1.firstName = "Zofia";


}