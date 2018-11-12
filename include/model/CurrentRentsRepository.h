//
// Created by pobi on 09.11.18.
//

#ifndef POBIZ01_CURRENTRENTSREPOSITORY_H
#define POBIZ01_CURRENTRENTSREPOSITORY_H

#include "Rent.h"
#include "Vehicle.h"
#include "VehicleRepository.h"
#include <list>

class currentRentsRepository {

    std::list<Rent *> rents;

public:

    void createRent(Rent *, VehicleRepository *);

    void removeRent(Rent *, VehicleRepository *);

    std::string rentReport();

    std::string getClientForRentedVehicle(Vehicle *);

};


#endif //POBIZ01_CURRENTRENTSREPOSITORY_H
