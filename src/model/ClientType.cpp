//
// Created by pobi on 22.11.18.
//

#include <model/ClientType.h>

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

    try {
        if (discount >= 1.0) {
            DiscountException tooHighDiscount("Zniżka wynosi 100% lub więcej!");
            throw tooHighDiscount;
        }
    }
    catch (DiscountException tooHigh) {
        std::cout << tooHigh.what();
    }

}

double ClientType::calculateClientTypeDiscount() {}