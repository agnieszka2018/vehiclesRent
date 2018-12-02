//
// Created by pobi on 29.11.18.
//

#include "ClientRepository.h"

void ClientRepository::addClient(ClientPtr client) {
    clients.push_back(client);
}

void ClientRepository::removeClient(ClientPtr client) {
    clients.remove(client);
}

void ClientRepository::modifyClientType(ClientPtr client, ClientTypePtr clientType) {
    client->setClientType(clientType);
}
