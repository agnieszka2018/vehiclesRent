//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include <string>
#include <memory>
#include "Client.h"
#include "Address.h"
#include "Vehicle.h"
#include "Rent.h"
#include "Bicycle.h"
#include "Car.h"
#include "Mope.h"
#include "MotorVehicle.h"
#include "RentsRepository.h"
#include "VehicleRepository.h"
#include "ClientType.h"
#include "RegularType.h"
#include "RentsManager.h"
#include "RentException.h"
#include "ClientException.h"

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