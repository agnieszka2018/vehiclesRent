//
// Created by pobi on 22.11.18.
//

#ifndef POBIZ01_CLIENTTYPE_H
#define POBIZ01_CLIENTTYPE_H

#include <string>

class ClientType {
    const int maxRentedCarAmount;
    double clientTypeDiscount;
    const std::string typeName;

public:
    ClientType(int maxRentedCarAmount, std::string typeName);
    virtual double calculateClientTypeDiscount();
    const int getMaxRentedCarAmount() const;
    double getClientTypeDiscount() const;
    std::string getTypeName() const;
};

#endif //POBIZ01_CLIENTTYPE_H
