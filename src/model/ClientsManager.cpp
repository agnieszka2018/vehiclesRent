//
// Created by pobi on 05.12.18.
//
#include "ClientsManager.h"

void ClientsManager::addClientToRepository(ClientRepoPtr clientRepo, ClientPtr client) {

    bool duplicate = false;

    std::list<ClientPtr> clientRepoList = clientRepo->getClients();

    std::list<ClientPtr>::iterator iter;
    for (iter = clientRepoList.begin(); iter != clientRepoList.end(); iter++) {
        //sprawdź czy nie ma już takiego klienta w Repozytorium Klientów
        if ((((*iter)->clientName()) == (client->clientName())) &&
            (((*iter)->getClientType()) == (client->getClientType())) &&
            (((*iter)->getAddress()) == (client->getAddress())) &&
            (((*iter)->getRegisteredAddress()) == (client->getRegisteredAddress())))
            duplicate = true; //jeśli spełnione wszystkie warunki jednocześnie, to znaczy, że jest to dokładnie ten sam klient!
    }

    try {
        if (duplicate == true) {
            ClientException duplicatedClient("Klient już istnieje w Repozytorium Klientów!");
            throw duplicatedClient;
        }
    } catch (ClientException duplicatedCli) {
        std::cout << duplicatedCli.what();
    }

    //dodawanie klienta do Repozytorium Klientów, jeśli nie ma jeszcze takiego w Repo
    clientRepo->addClient(client);

}

void ClientsManager::deleteClientFromRepository(ClientRepoPtr clientRepo, ClientPtr client) {

    clientRepo->removeClient(client);
}


void ClientsManager::deleteClientFromRepository(ClientRepoPtr clientRepo, int number) {

    clientRepo->removeClient(number);
}

