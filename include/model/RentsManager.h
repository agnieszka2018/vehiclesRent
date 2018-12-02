//
// Created by pobi on 01.12.18.
//

#ifndef POBIZ01_RENTSMANAGER_H
#define POBIZ01_RENTSMANAGER_H

#include "Client.h"
#include "Vehicle.h"
#include "VehicleRepository.h"

class RentsManager {
private:

public:
    RentsManager();

    virtual ~RentsManager();

    void rentVehicle(Vehicle *, Client *, VehicleRepository *);

    void returnVehicle();

    void getAllClientRents();

    void checkClientRentBallance(Client *);

    void changeClientType();

};

#endif //POBIZ01_RENTSMANAGER_H
