//
// Created by pobi on 28.11.18.
//

#include "VipType.h"

VipType::VipType() : ClientType(12, "Klient VIP") {}

VipType::~VipType() {

}

double VipType::calculateClientTypeDiscount() {
    return (0.01 * getMaxRentedCarAmount() * getMaxRentedCarAmount()) - 0.6;   //stały rabat = 0.84
}
