//
// Created by pobi on 09.11.18.
//

#ifndef POBIZ01_RENTSREPOSITORY_H
#define POBIZ01_RENTSREPOSITORY_H

#include "model/rent/Rent.h"
#include "vehicle/Vehicle.h"
#include "VehicleRepository.h"
#include "model/client/Address.h"
#include "model/client/Client.h"
#include <algorithm>
#include <list>
#include <memory>
#include <string>
#include "model/searchEngine/SearchEngine.h"
#include "model/exceptions/RentException.h"

typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;

class RentsRepository {

    std::list<RentPtr> currentRents;
    std::list<RentPtr> archiveRents;

public:

    void createRent(RentPtr, VehicleRepoPtr);

    void removeRent(RentPtr, VehicleRepoPtr);

    std::string rentReport();

    std::string getClientForRentedVehicle(VehiclePtr);

    RentPtr findRent(SearchEngine);

    RentPtr operator()(int);

    std::list<RentPtr> getCurrentRents();
};


#endif //POBIZ01_RENTSREPOSITORY_H
