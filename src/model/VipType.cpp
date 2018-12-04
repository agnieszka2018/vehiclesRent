//
// Created by pobi on 28.11.18.
//

#include "VipType.h"

VipType::VipType() : ClientType(12, "Klient VIP") {}

VipType::~VipType() {

}

double VipType::calculateClientTypeDiscount() {
    double discount = (0.01 * getMaxRentedCarAmount() * getMaxRentedCarAmount()) - 0.6;   //stały rabat = 0.84

    checkDiscount(discount); //sprawdzam czy rabat nie jest zbyt wysoki

    return discount;
}
