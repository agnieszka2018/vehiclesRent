//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include "./include/model/Client.h"
#include "./include/model/Address.h"
#include "Rent.h"

using namespace std;

int main() {
    Address *actuall_address = new Address("Mickiewicza", "7");
    Client klient_1("Jan", "Kowalski", "123456789", actuall_address);
    Client klient_2("Kamil", "Nowak", "987654321", actuall_address);

    cout << klient_1.clientInfo() << endl;
    cout << klient_2.clientInfo();

    //cout << "Adres  zamieszkania przed zmianą: " << klient_1.clientInfo();

    actuall_address->changeInfo("Promienna", "5");
    cout << "\nAdres  zamieszkania po zmianie: " << klient_1.clientInfo();
    cout << "\nAdres  zamieszkania po zmianie: " << klient_2.clientInfo() << endl;

    delete actuall_address;
}