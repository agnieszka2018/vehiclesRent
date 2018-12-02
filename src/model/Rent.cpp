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

class Client;                                    //???

int Rent::rentDuration() {

    time_duration d = endTime - startTime;
    long secs = d.total_seconds();
    float days = ((secs / 60.0) / 60) / 24;
    int period;
    if (days - int(days) != 0) period = days + 1;
    else period = days;

    return period;
}

std::string Rent::rentInfo() {

    std::stringstream ss;
    ss << "\nwypozyczenie:\n";
    ss << "uuid: " << uuid << std::endl;
    ss << "wypozyczajacy:\n" << client->clientName() << std::endl;
    ss << "pojazd: " << vehicle->vehicleInfo();
    ss << "start time: " << startTime << std::endl;
    if (endTime != startTime) ss << "end time: " << endTime << std::endl;
    ss << "czas wypozyczenia: " << rentDuration() << std::endl;

    return ss.str();
}

std::string Rent::rentInfoFromClient() {

    std::stringstream ss;
    ss << "\nwypozyczenie:\n";
    ss << "uuid: " << uuid;
    ss << "\npojazd: " << vehicle->vehicleInfo();
    ss << "start time: " << startTime << std::endl;
    if (endTime != startTime) ss << "end time: " << endTime << std::endl;
    ss << "czas wypozyczenia: " << rentDuration() << std::endl;

    return ss.str();
}


Rent::~Rent() {
    std::cout << "destruktor Rent jest wywolany" << std::endl;
    client->deleteRent(this);   //usuwamy wypożyczenie z listy wypożyczeń klienta
    //std::cout << "Koszt wypozyczenia"<< rent;
}

Rent::Rent(const local_date_time &startTime, Vehicle *vehicle, Client *client) : startTime(startTime), vehicle(vehicle),
                                                                                 client(client), endTime(startTime) {
    uuid = boost::uuids::random_generator()();

    client->addRent(this);   //dodajemy wypożyczenie do listy wypożyczeń klienta
    vehicle->modifyClient(client);

}

void Rent::returnVehicle() {
    time_zone_ptr zone(new posix_time_zone("UTC+1"));
    local_date_time now = local_sec_clock::local_time(zone);
    endTime = now;

    std::cout << "Wypozyczenie trwalo: " << rentDuration() << std::endl;
    cost = rentDuration() * vehicle->getActuallRentalPrice();

    std::cout << "Całkowity koszt wypozyczenia: " << cost << std::endl;
}

Vehicle *Rent::getVehicle() const {
    return vehicle;
}






