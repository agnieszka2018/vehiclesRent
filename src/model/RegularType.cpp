//
// Created by pobi on 28.11.18.
//

#include "RegularType.h"
#include <iostream>

RegularType::~RegularType() {}

RegularType::RegularType() : ClientType(5, "Klient zwykly") {}

double RegularType::calculateClientTypeDiscount() {
    return 0.0;
}



