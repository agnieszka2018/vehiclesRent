//
// Created by pobi on 05.12.18.
//
#include "ClientsManager.h"

void ClientsManager::addClientToRepository(ClientRepoPtr clientRepo, ClientPtr client) {

    bool duplicate = false;

    std::list<ClientPtr> clientRepoList = clientRepo->getClients();
    size_t size = clientRepoList.size();   //jesli lista jest pusta z zasady nie sprawdzam czy jest powtorzenie

    if (size != 0) {

        std::list<ClientPtr>::iterator iter;
        for (iter = clientRepoList.begin(); iter != clientRepoList.end(); iter++) {
            //sprawdź czy nie ma już takiego klienta w Repozytorium Klientów
            if ((**iter) == (*client))
                duplicate = true;
        }

        //wyjątek
        if (duplicate == true)
            throw ClientException("Klient już istnieje w Repozytorium Klientów!");
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