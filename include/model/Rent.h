//
// Created by pobi on 28.10.18.
//

#ifndef POBIZ01_RENT_H
#define POBIZ01_RENT_H

#include <boost/date_time/local_time/local_time.hpp>
#include <boost/uuid/random_generator.hpp>
#include <string>

class Rent{
private:
    boost::uuids::uuid uuid;
public:
        int rentDuration();
        ~Rent();
        void returnVehicle();
        std::string rentInfo();

};

#endif //POBIZ01_RENT_H
