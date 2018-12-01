//
// Created by pobi on 09.11.18.
//

#ifndef POBIZ01_RENTSREPOSITORY_H
#define POBIZ01_RENTSREPOSITORY_H

#include "Rent.h"
#include "Vehicle.h"
#include "VehicleRepository.h"
#include <list>

class RentsRepository {

    std::list<Rent *> rents;

public:

    void createRent(Rent *, VehicleRepository *);

    void removeRent(Rent *, VehicleRepository *);

    std::string rentReport();

    std::string getClientForRentedVehicle(Vehicle *);

};


#endif //POBIZ01_RENTSREPOSITORY_H
