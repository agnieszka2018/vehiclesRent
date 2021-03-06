//
// Created by pobi on 28.10.18.
//

#ifndef POBIZ01_RENT_H
#define POBIZ01_RENT_H

#include <boost/uuid/random_generator.hpp>
#include <string>
#include "model/client/Client.h"
#include "boost/date_time/local_time/local_time.hpp"
#include <memory>
#include "vehicle/Vehicle.h"

class Client;

class Vehicle;

typedef std::shared_ptr<Vehicle> VehiclePtr;
typedef std::shared_ptr<Client> ClientPtr;


class Rent {
private:
    boost::uuids::uuid uuid;
    boost::local_time::local_date_time startTime;
    boost::local_time::time_zone_ptr startZone;
    boost::local_time::local_date_time endTime;
    //boost::local_time::time_zone_ptr endZone;
    double cost;
    VehiclePtr vehicle;
    ClientPtr client;

public:

    int rentDuration();

    ~Rent();

    std::string returnVehicle();

    std::string rentInfo();

    std::string rentInfoFromClient();

    VehiclePtr getVehicle();

    double getCost();

    bool operator==(Rent &);

    //bool operator==(Rent &);  wersja alternatywna

    Rent(boost::local_time::local_date_time &startTime, VehiclePtr vehicle, ClientPtr client);

    ClientPtr getClient();

};

#endif //POBIZ01_RENT_H
