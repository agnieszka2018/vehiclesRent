//
// Created by pobi on 28.11.18.
//

#include "VipType.h"

VipType::VipType() : ClientType(10, calculateClientTypeDiscount(), "Klient VIP") {}

VipType::~VipType() {

}

double VipType::calculateClientTypeDiscount() {
    return 2;
}
