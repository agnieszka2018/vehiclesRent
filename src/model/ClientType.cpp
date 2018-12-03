//
// Created by pobi on 22.11.18.
//

#include "ClientType.h"

const int ClientType::getMaxRentedCarAmount() const {
    return maxRentedCarAmount;
}

double ClientType::getClientTypeDiscount() const {
    return clientTypeDiscount;
}


double ClientType::calculateClientTypeDiscount(){}

ClientType::ClientType(int maxRentedCarAmount, std::string typeName) : maxRentedCarAmount{maxRentedCarAmount}, typeName{typeName} {}

std::string ClientType::getTypeName() const {
    return typeName;
}
