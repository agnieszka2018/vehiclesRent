//
// Created by pobi on 05.12.18.
//

#ifndef POBIZ01_CLIENTSMANAGER_H
#define POBIZ01_CLIENTSMANAGER_H

#include <memory>
#include <list>
#include "model/repositories/ClientRepository.h"
#include "model/client/Client.h"
#include "model/exceptions/ClientException.h"

typedef std::shared_ptr<ClientRepository> ClientRepoPtr;
typedef std::shared_ptr<Client> ClientPtr;

class ClientsManager {

public:

    void addClientToRepository(ClientRepoPtr, ClientPtr);

    void deleteClientFromRepository(ClientRepoPtr, ClientPtr);

    void deleteClientFromRepository(ClientRepoPtr, int);
};

#endif //POBIZ01_CLIENTSMANAGER_H
