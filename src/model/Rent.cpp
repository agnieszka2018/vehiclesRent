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
#include "boost/date_time/local_time/local_time.hpp"

using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;


std::string Rent::rentInfo() {
    uuid = boost::uuids::random_generator()();
    std::cout << uuid << std::endl;
}

Rent::~Rent() {
    std::cout << "destruktor Rent jest wywolany" << std::endl;
    //std::cout << "Koszt wypozyczenia"<< rent;
}





