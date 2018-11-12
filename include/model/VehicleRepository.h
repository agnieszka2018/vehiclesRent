//
// Created by pobi on 11.11.18.
//

#ifndef POBIZ01_VEHICLEREPOSITORY_H
#define POBIZ01_VEHICLEREPOSITORY_H

#include <iostream>
#include <string>
#include <list>
#include "Vehicle.h"


class VehicleRepository {

    std::list<Vehicle *> vehicles;


public:

    void createVehicle(Vehicle*);

    void removeVehicle(Vehicle*);

    std::string vehicleReport();

};

#endif //POBIZ01_VEHICLEREPOSITORY_H
