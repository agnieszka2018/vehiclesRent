//
// Created by pobi on 29.11.18.
//

#include "model/repositories/ClientRepository.h"

void ClientRepository::addClient(ClientPtr client) {
    clients.push_back(client);
}

void ClientRepository::removeClient(ClientPtr client) {
    clients.remove(client);
}

void ClientRepository::removeClient(int clientIndex) {
    //usuń klienta o danym numerze indeksu

    int liczba = 0;

    std::list<ClientPtr>::iterator iter;
    for (iter = clients.begin(); iter != clients.end(); iter++) {
        //znaleźć odpowiedni indeks klienta
        if (liczba == clientIndex)
            removeClient(*iter);
        liczba++;
    }
}

void ClientRepository::modifyClientType(ClientPtr client, ClientTypePtr clientType) {
    client->setClientType(clientType);
}

std::list<ClientPtr> ClientRepository::getClients() {
    return clients;
}

ClientPtr ClientRepository::findClient(int number) {

    //szukanie klienta po numerze indeksu
    int liczba = 1;

    std::list<ClientPtr>::iterator iter;
    for (iter = clients.begin(); iter != clients.end(); iter++) {
        if (liczba == number)
            return *iter;
        liczba++;
    }
}

ClientPtr ClientRepository::operator()(int number) {

    //metoda zwraca wskaźnik do klienta o danym indeksie
    return findClient(number);
}

bool ClientRepository::checkIfIsInRepo(ClientPtr client2) {

    std::list<ClientPtr>::iterator iter;

    for (iter = clients.begin(); iter != clients.end(); iter++) {
        if (client2 == (*iter))
            return true;
    }

    return false;
}