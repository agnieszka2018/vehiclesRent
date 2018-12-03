//
// Created by pobi on 28.11.18.
//

#include "VipType.h"

VipType::VipType() : ClientType(15, "Klient VIP") {}

VipType::~VipType() {

}

double VipType::calculateClientTypeDiscount() {
    return 2;   //zmodyfikować
}
