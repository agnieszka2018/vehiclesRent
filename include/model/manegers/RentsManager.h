//
// Created by pobi on 01.12.18.
//

#ifndef POBIZ01_RENTSMANAGER_H
#define POBIZ01_RENTSMANAGER_H

#include "model/client/Client.h"
#include "vehicle/Vehicle.h"
#include "model/repositories/VehicleRepository.h"
#include "model/repositories/RentsRepository.h"
#include "model/client/BusinessType.h"
#include "model/client/VipType.h"
#include "model/client/RegularType.h"
#include "model/exceptions/RentException.h"
#include "model/exceptions/ClientException.h"
#include <memory>
#include <vector>

using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
typedef std::shared_ptr<RentsRepository> RentsRepoPtr;
typedef std::shared_ptr<BusinessType> BusinessTypePtr;
typedef std::shared_ptr<VipType> VipTypePtr;
typedef std::shared_ptr<RegularType> RegularTypePtr;


class RentsManager {

public:
    RentsManager();

    virtual ~RentsManager();

    std::vector<RentPtr> getAllClientRents(ClientPtr);

    double checkClientRentBallance(ClientPtr);

    void changeClientType(ClientPtr);

    void rentVehicle(VehiclePtr, ClientPtr, VehicleRepoPtr, RentsRepoPtr);

    void returnVehicle(ClientPtr, RentsRepoPtr, RentPtr, VehicleRepoPtr);
};

#endif //POBIZ01_RENTSMANAGER_H
