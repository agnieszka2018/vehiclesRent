//
// Created by pobi on 28.10.18.
//
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Client.h"
#include "Rent.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <model/Rent.h>

#include "boost/date_time/local_time/local_time.hpp"

using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

int Rent::rentDuration() {

    time_duration d = endTime - startTime;
    long secs = d.total_seconds();
    float days = ((secs/60.0)/60)/24;
    int period;
    if (days - int(days) != 0) period = days+1;
    else period = days;

    return period;
}

std::string Rent::rentInfo() {

    std::cout << "\nwypozyczenie:\n";
    std::cout << "uuid: " <<uuid << std::endl;
    std::cout << "wypozyczajacy:\n" << client->clientInfo() << std::endl;
    std::cout << "pojazd: "<< vehicle->vehicleInfo();
    std::cout << "start time: "<< startTime <<std::endl;
    std::cout << "end time: "<< endTime <<std::endl;
    std::cout << "czas wypozyczenia: " << rentDuration();
}

Rent::~Rent() {
    std::cout << "destruktor Rent jest wywolany" << std::endl;
    //std::cout << "Koszt wypozyczenia"<< rent;
}

Rent::Rent(const local_date_time &startTime, Vehicle *vehicle, Client *client) : startTime(startTime), vehicle(vehicle),
                                                                                 client(client), endTime(startTime) {
    uuid = boost::uuids::random_generator()();
}

void Rent::returnVehicle() {
    time_zone_ptr zone(new posix_time_zone("UTC"));
    local_date_time now = local_sec_clock::local_time(zone);
    endTime = now;
}








