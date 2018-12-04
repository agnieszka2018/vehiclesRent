//
// Created by pobi on 01.12.18.
//

#ifndef POBIZ01_RENTSMANAGER_H
#define POBIZ01_RENTSMANAGER_H

#include "Client.h"
#include "Vehicle.h"
#include "VehicleRepository.h"
#include "RentsRepository.h"
#include "BusinessType.h"
#include "VipType.h"
#include "RegularType.h"
#include "RentException.h"
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

//class RentException;

class RentsManager {
private:

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
