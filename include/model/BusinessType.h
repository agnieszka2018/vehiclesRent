//
// Created by pobi on 28.11.18.
//

#ifndef POBIZ01_BUSINESSTYPE_H
#define POBIZ01_BUSINESSTYPE_H

#include "ClientType.h"


class BusinessType : public ClientType{
    double calculateClientTypeDiscount() override;
public:
    BusinessType();

    virtual ~BusinessType();
};


#endif //POBIZ01_BUSINESSTYPE_H
