//
// Created by pobi on 13.12.18.
//

#ifndef POBIZ01_SEARCHENGINE_H
#define POBIZ01_SEARCHENGINE_H

#include <string>
#include <memory>
#include "Rent.h"

typedef std::shared_ptr<Rent> RentPtr;

class SearchEngine {
    bool byName;
    std::string name;

    bool byCarId;
    std::string carId;

public:
    bool operator()(RentPtr);
};

#endif //POBIZ01_SEARCHENGINE_H
