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

ClientType::ClientType(int maxRentedCarAmount, std::string typeName) : maxRentedCarAmount{maxRentedCarAmount},
                                                                       typeName{typeName} {}

std::string ClientType::getTypeName() const {
    return typeName;
}

void ClientType::checkDiscount(double discount) {

    if (discount >= 1.0) {
        throw DiscountException("Zniżka wynosi 100% lub więcej!");
    }
}

double ClientType::calculateClientTypeDiscount() {}