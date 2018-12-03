//
// Created by pobi on 09.11.18.
//

#ifndef POBIZ01_RENTSREPOSITORY_H
#define POBIZ01_RENTSREPOSITORY_H

#include "Rent.h"
#include "Vehicle.h"
#include "VehicleRepository.h"
#include <list>
#include <memory>

typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Rent> RentPtr;

class RentsRepository {

    std::list<RentPtr> currentRents;
    std::list<RentPtr> archiveRents;

public:

    void createRent(RentPtr, VehicleRepoPtr);

    void removeRent(RentPtr, VehicleRepoPtr);

    std::string rentReport();

    std::string getClientForRentedVehicle(VehiclePtr);

};


#endif //POBIZ01_RENTSREPOSITORY_H
