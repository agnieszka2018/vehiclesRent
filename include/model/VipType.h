//
// Created by pobi on 28.11.18.
//

#ifndef POBIZ01_VIPTYPE_H
#define POBIZ01_VIPTYPE_H


#include "ClientType.h"

class VipType : public ClientType {

    double calculateClientTypeDiscount() override;

public:
    VipType();

    virtual ~VipType();
};


#endif //POBIZ01_VIPTYPE_H
