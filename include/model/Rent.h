//
// Created by pobi on 28.10.18.
//

#ifndef POBIZ01_RENT_H
#define POBIZ01_RENT_H

#include <boost/uuid/random_generator.hpp>
#include <string>
#include "boost/date_time/local_time/local_time.hpp"
#include <memory>
#include "Vehicle.h"
#include "Client.h"

typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Client> ClientPtr;

class Client;
class Vehicle;

class Rent {
private:
    boost::uuids::uuid uuid;
    boost::local_time::local_date_time startTime;
    boost::local_time::time_zone_ptr startZone;
    boost::local_time::local_date_time endTime;
    //boost::local_time::time_zone_ptr endZone;
    float cost;
    VehiclePtr vehicle;
    ClientPtr client;

public:

    int rentDuration();

    ~Rent();

    void returnVehicle();

    std::string rentInfo();

    std::string rentInfoFromClient();

    VehiclePtr getVehicle();

    Rent(boost::local_time::local_date_time &startTime, VehiclePtr vehicle, ClientPtr client);
};

#endif //POBIZ01_RENT_H
