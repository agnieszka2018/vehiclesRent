//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include <string>
#include <memory>
#include "model/client/Client.h"
#include "model/client/Address.h"
#include "vehicle/Vehicle.h"
#include "model/rent/Rent.h"
#include "vehicle/Bicycle.h"
#include "vehicle/Car.h"
#include "vehicle/Mope.h"
#include "vehicle/MotorVehicle.h"
#include "model/repositories/RentsRepository.h"
#include "model/repositories/VehicleRepository.h"
#include "model/client/ClientType.h"
#include "model/client/RegularType.h"
#include "model/manegers/RentsManager.h"
#include "model/exceptions/RentException.h"
#include "model/exceptions/ClientException.h"

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

//typedef boost::shared_ptr<dst_calc_rules> local_time::dst_calc_rule_ptr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Mope> MopePtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;

int main() {

    try {   //TODO

    }
    catch (VehicleException vehicle) {
        std::cout << vehicle.what();
    }
    catch (RentException brakPoj) {
        std::cout << brakPoj.what();
    }
    catch (ClientException duplicatedCli) {
        std::cout << duplicatedCli.what();
    }
    catch (DiscountException tooHigh) {
        std::cout << tooHigh.what();
    }

}