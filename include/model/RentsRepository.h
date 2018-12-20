//
// Created by pobi on 09.11.18.
//

#ifndef POBIZ01_RENTSREPOSITORY_H
#define POBIZ01_RENTSREPOSITORY_H

#include "Rent.h"
#include "Vehicle.h"
#include "VehicleRepository.h"
#include "Address.h"
#include "Client.h"
#include <algorithm>
#include <list>
#include <memory>
#include <string>
#include "SearchEngine.h"
#include "RentException.h"

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

    bool operator==(Rent);
};


#endif //POBIZ01_RENTSREPOSITORY_H
