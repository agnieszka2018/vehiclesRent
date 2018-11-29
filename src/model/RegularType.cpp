//
// Created by pobi on 28.11.18.
//

#include <model/RegularType.h>

#include "RegularType.h"
#include <iostream>

RegularType::~RegularType() {

}

RegularType::RegularType() : ClientType(5, calculateClientTypeDiscount(), "Klient zwykly") {

}

double RegularType::calculateClientTypeDiscount() {
    return 0;
}



