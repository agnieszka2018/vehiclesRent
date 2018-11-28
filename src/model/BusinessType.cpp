//
// Created by pobi on 28.11.18.
//

#include <model/BusinessType.h>

#include "BusinessType.h"

BusinessType::BusinessType() : ClientType(10, calculateClientTypeDiscount()) {}

BusinessType::~BusinessType() {

}

double BusinessType::calculateClientTypeDiscount() {
    return 1;
}
