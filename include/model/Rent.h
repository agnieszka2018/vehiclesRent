//
// Created by pobi on 28.10.18.
//

#ifndef POBIZ01_RENT_H
#define POBIZ01_RENT_H

#include <boost/uuid/random_generator.hpp>
#include <string>
#include "boost/date_time/local_time/local_time.hpp"

class Client;

class Vehicle;

class Rent {
private:
    boost::uuids::uuid uuid;

    boost::local_time::local_date_time startTime;
    //boost::local_time::time_zone_ptr timeZone;        /* strefa czasowa */
    boost::local_time::local_date_time endTime;
    //boost::local_time::time_zone_ptr endZone;

    float cost;
    Vehicle *vehicle = nullptr;
    Client *client = nullptr;

public:
    Rent(const boost::local_time::local_date_time &startTime, Vehicle *vehicle, Client *client = nullptr);

    int rentDuration();

    void returnVehicle();

    std::string rentInfo();

    ~Rent();
};

#endif //POBIZ01_RENT_H
