//
// Created by pobi on 28.10.18.
//
#include <iostream>
#include <string>
#include "Rent.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "boost/date_time/local_time/local_time.hpp"

using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;


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
    ss << "wypozyczajacy:\n" << client->getFirstName() << std::endl;
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


Rent::~Rent() {}

Rent::Rent(local_date_time &startTime, VehiclePtr vehicle, ClientPtr client) : startTime(startTime), vehicle(vehicle),
                                                                               client(client), endTime(startTime) {
    uuid = boost::uuids::random_generator()();

    vehicle->modifyClient(client);
}

void Rent::returnVehicle() {
    time_zone_ptr zone(new posix_time_zone("UTC+1"));
    local_date_time now = local_sec_clock::local_time(zone);
    endTime = now;

    std::cout << "Wypozyczenie trwalo: " << rentDuration() << std::endl;
    cost = rentDuration() * vehicle->getActuallRentalPrice();

    std::cout << "Całkowity koszt wypozyczenia (bez rabatu): " << cost << std::endl;
}

VehiclePtr Rent::getVehicle() {
    return vehicle;
}

double Rent::getCost() {
    return cost;
}

bool Rent::operator==(Rent &rent2) {

    //sprawdzam czy dwa obiekty są sobie równe
    if ((*this) == rent2)
        return true;
    else
        return false;
}

/*
bool Rent::operator==(Rent &rent2) {

    //sprawdzam czy dwa obiekty są sobie równe
    if (((this->uuid) == (rent2.uuid)) && ((this->client) == (rent2.client)) && ((this->vehicle) == (rent2.vehicle)) &&
        ((this->cost) == (rent2.cost)))
        return true;
    else
        return false;
} */

ClientPtr Rent::getClient() {
    return client;
}