//
// Created by pobi on 11.11.18.
//

#ifndef POBIZ01_VEHICLEREPOSITORY_H
#define POBIZ01_VEHICLEREPOSITORY_H

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <algorithm>
#include "Vehicle.h"
#include "VehicleException.h"

//class Vehicle;

typedef std::shared_ptr<Vehicle> VehiclePtr;

class VehicleRepository {

    std::list<VehiclePtr> vehicles;


public:
    void createVehicle(VehiclePtr);

    void removeVehicle(VehiclePtr);

    std::string vehicleReport();

    std::list<VehiclePtr> getVehicles();

    VehiclePtr findVehicle(int);

    VehiclePtr operator()(int);

    virtual ~VehicleRepository();
};

#endif //POBIZ01_VEHICLEREPOSITORY_H
