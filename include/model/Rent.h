//
// Created by pobi on 28.10.18.
//

#ifndef POBIZ01_RENT_H
#define POBIZ01_RENT_H

#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/random_generator.hpp>
#include <string>
#include "boost/date_time/local_time/local_time.hpp"

class Client;

class Rent{
private:
    boost::uuids::uuid uuid;
    boost::local_time::local_date_time startTime;
    boost::local_time::time_zone_ptr startZone;
    boost::local_time::local_date_time endTime;
    boost::local_time::time_zone_ptr endZone;
    //okres wypozyczenia jest obliczany przez local_time_period z boost
    float cost;
    //pojazd
    Client *client= nullptr;

public:
        int rentDuration();
        ~Rent();
        void returnVehicle();
        std::string rentInfo();

};

#endif //POBIZ01_RENT_H
