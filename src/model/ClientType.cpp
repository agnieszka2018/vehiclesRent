//
// Created by pobi on 22.11.18.
//

#include "ClientType.h"

const int ClientType::getMaxRentedCarAmount() const {
    return maxRentedCarAmount;
}

int ClientType::getClientTypeDiscount() const {
    return clientTypeDiscount;
}


double ClientType::calculateClientTypeDiscount(){}

ClientType::ClientType(int maxRentedCarAmount, int clientTypeDiscount, std::string typeName) : maxRentedCarAmount(maxRentedCarAmount),
                                                                               clientTypeDiscount(clientTypeDiscount), typeName(typeName) {}

std::string ClientType::getTypeName() const {
    return typeName;
}
