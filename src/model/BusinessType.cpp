//
// Created by pobi on 28.11.18.
//

#include <model/BusinessType.h>

#include "BusinessType.h"

BusinessType::BusinessType() : ClientType(7, "Klient biznesowy") {}

BusinessType::~BusinessType() {

}

double BusinessType::calculateClientTypeDiscount() {
    return 0.1 * getMaxRentedCarAmount(); //stały rabat dla klientów biznesowych = 0.7
}
