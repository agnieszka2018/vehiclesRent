//
// Created by pobi on 01.12.18.
//

#ifndef POBIZ01_RENTSMANAGER_H
#define POBIZ01_RENTSMANAGER_H

#include "Client.h"
#include "Vehicle.h"
#include "VehicleRepository.h"
#include "RentsRepository.h"
#include <memory>

using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
typedef std::shared_ptr<RentsRepository> RentsRepoPtr;


class RentsManager {
private:

public:
    RentsManager();

    virtual ~RentsManager();

    void rentVehicle(VehiclePtr, ClientPtr, VehicleRepoPtr, RentsRepoPtr);

    void returnVehicle();

    void getAllClientRents();

    void checkClientRentBallance(ClientPtr);

    void changeClientType();

};

#endif //POBIZ01_RENTSMANAGER_H
