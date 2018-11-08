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

class Client;                //???


Rent::Rent(const local_date_time &startTime, Vehicle *vehicle, Client *client) : startTime(startTime),
                                                                                 vehicle(vehicle),
                                                                                 client(client),
                                                                                 endTime(startTime) {   //endTime tylko liście inicjalizacyjnej, a nie w liście param, bo nie trzeba podawac dwa razy startTime

    uuid = boost::uuids::random_generator()();

    client->modifyRent(this);

}

int Rent::rentDuration() {

    time_duration d = endTime - startTime;                           //endTime domyślnie ustawiony na startTime, dopiero przy oddaniu nadpisujemy endTime
    long secs = d.total_seconds();
    float days = ((secs / 60.0) / 60) / 24;                           //sekundy przeliczone na dni
    int period = 0;

    if (days - static_cast<int>(days) != 0) period = days + 1;       //rzutowanie float na int
    else period = days;

    return period;
}

std::string Rent::rentInfo() {

    std::stringstream ss;
    ss << "\nwypozyczenie:\n";
    ss << "uuid: " << uuid << std::endl;
    //ss << "wypozyczajacy:\n" << client->clientInfo() << std::endl;
    ss << "dane klienta " << client->getClient();
    ss << "\npojazd: " << vehicle->vehicleInfo();
    ss << "start time: " << startTime << std::endl;
    if (endTime != startTime) ss << "end time: " << endTime << std::endl;
    ss << "czas wypozyczenia: " << rentDuration() << std::endl;

    return ss.str();
}


void Rent::returnVehicle() {
    time_zone_ptr zone(new posix_time_zone("UTC+1"));             //deklaracja i inicjalizacja zone
    local_date_time now = local_sec_clock::local_time(zone);
    endTime = now;

    std::cout << "Wypozyczenie trwalo: " << this->rentDuration() << std::endl;
    std::cout << "Koszt wypozyczenia: " << this->rentDuration() * vehicle->getPrice() << std::endl;
}


Rent::~Rent() {
    std::cout << "destruktor Rent jest wywolany" << std::endl;
    //std::cout << "Koszt wypozyczenia"<< rent;
}






