//
// Created by pobi on 28.11.18.
//

#include "BusinessType.h"

BusinessType::BusinessType() : ClientType(7, "Klient biznesowy") {}

BusinessType::~BusinessType() {}

double BusinessType::calculateClientTypeDiscount() {
    double discount = 0.1 * getMaxRentedCarAmount(); //stały rabat dla klientów biznesowych = 0.7

    checkDiscount(discount); //sprawdzam czy rabat nie jest zbyt wysoki

    return discount;
}
