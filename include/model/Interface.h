//
// Created by pobi on 04.12.18.
//

#ifndef POBIZ01_INTERFACE_H
#define POBIZ01_INTERFACE_H

#include <iostream>
#include <string>
#include <memory>
#include "Client.h"
#include "Address.h"
#include "Vehicle.h"
#include "Rent.h"
#include "Car.h"
#include "RentsRepository.h"
#include "VehicleRepository.h"
#include "ClientType.h"
#include "RegularType.h"
#include "RentsManager.h"
#include "RentException.h"
#include "ClientException.h"
#include "Interface.h"

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
typedef std::shared_ptr<RentsRepository> RentsRepoPtr;

class Interface {

public:

    std::string rentExceptionMessage();

};

#endif //POBIZ01_INTERFACE_H
