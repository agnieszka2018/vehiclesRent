//
// Created by pobi on 22.11.18.
//

#ifndef POBIZ01_CLIENTTYPE_H
#define POBIZ01_CLIENTTYPE_H

#include <string>
#include "model/exceptions/DiscountException.h"
#include <iostream>

class ClientType {
    const int maxRentedCarAmount;
    double clientTypeDiscount;
    const std::string typeName;

public:
    ClientType(int maxRentedCarAmount, std::string typeName);
    const int getMaxRentedCarAmount() const;
    double getClientTypeDiscount() const;
    std::string getTypeName() const;
    void checkDiscount(double);
    virtual double calculateClientTypeDiscount();
    virtual ~ClientType();
};

#endif //POBIZ01_CLIENTTYPE_H
