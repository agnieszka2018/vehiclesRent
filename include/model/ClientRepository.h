//
// Created by pobi on 29.11.18.
//

#ifndef POBIZ01_CLIENTREPOSITORY_H
#define POBIZ01_CLIENTREPOSITORY_H

#include <list>
#include "Client.h"
#include "ClientType.h"

class ClientRepository {

    std::list <Client *> clients;

public:

    void addClient(Client *);
    void removeClient(Client *);
    void modifyClientType(Client *, ClientType *);
};


#endif //POBIZ01_CLIENTREPOSITORY_H
