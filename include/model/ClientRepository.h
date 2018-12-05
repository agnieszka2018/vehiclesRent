//
// Created by pobi on 29.11.18.
//

#ifndef POBIZ01_CLIENTREPOSITORY_H
#define POBIZ01_CLIENTREPOSITORY_H

#include <list>
#include <memory>
#include "Client.h"
#include "ClientType.h"

typedef std::shared_ptr<Client> ClientPtr;

class ClientRepository {

    std::list <ClientPtr> clients;

public:

    void addClient(ClientPtr);
    void removeClient(ClientPtr);
    void removeClient(int);
    void modifyClientType(ClientPtr, ClientTypePtr);
    std::list<ClientPtr> getClients();
};


#endif //POBIZ01_CLIENTREPOSITORY_H
