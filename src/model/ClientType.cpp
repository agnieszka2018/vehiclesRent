//
// Created by pobi on 22.11.18.
//

#include <model/ClientType.h>

const int ClientType::getMaxRentedCarAmount() const {
    return maxRentedCarAmount;
}

int ClientType::getClientTypeDiscount() const {
    return clientTypeDiscount;
}


double ClientType::calculateClientTypeDiscount(){}

ClientType::ClientType(const int maxRentedCarAmount, int clientTypeDiscount) : maxRentedCarAmount(maxRentedCarAmount),
                                                                               clientTypeDiscount(clientTypeDiscount) {}
