//
// Created by pobi on 28.11.18.
//

#ifndef POBIZ01_REGULARTYPE_H
#define POBIZ01_REGULARTYPE_H

#include "ClientType.h"


class RegularType : public ClientType {
    double calculateClientTypeDiscount() override;

public:
    RegularType();
    virtual ~RegularType();
};


#endif //POBIZ01_REGULARTYPE_H
