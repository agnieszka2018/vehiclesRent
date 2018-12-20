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
    bool byName = false;
    std::string name;

    bool byCarId = false;
    std::string carId;

public:

    SearchEngine(std::string name = "0", std::string carId = "0");  //w konstruktorze przekazać wartości, a nie w setterze

    bool operator()(RentPtr);

};

#endif //POBIZ01_SEARCHENGINE_H
