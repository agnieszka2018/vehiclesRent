//
// Created by pobi on 29.11.18.
//

#include <model/ClientRepository.h>

#include "ClientRepository.h"

void ClientRepository::addClient(Client *client) {
    clients.push_back(client);
}

void ClientRepository::removeClient(Client *client) {
    clients.remove(client);
}

void ClientRepository::modifyClientType(Client *client, ClientType *clientType) {
    client->setClientType(clientType);
}
