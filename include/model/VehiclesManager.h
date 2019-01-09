//
// Created by pobi on 05.12.18.
//

#ifndef POBIZ01_VEHICLESMANAGER_H
#define POBIZ01_VEHICLESMANAGER_H

#include <list>
#include <memory>
#include "VehicleRepository.h"
#include "Vehicle.h"
#include "VehicleException.h"

typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;

class VehiclesManager {

public:

    void addVehicleToRepository(VehicleRepoPtr, VehiclePtr);

    void deleteVehicleFromRepository(VehicleRepoPtr, VehiclePtr);

};

#endif //POBIZ01_VEHICLESMANAGER_H
