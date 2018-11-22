//
// Created by pobi on 22.11.18.
//

#include <model/ClientType.h>

const int ClientType::getMaxVehicle(int type) const {

    if (type == 1)
        return 1;
    else if (type == 2)
        return 2;
    else if (type == 3)
        return 3;
    else if (type == 4)
        return 4;
    else
        return 0;
}

const int ClientType::getDiscount(int type) const {
    if (type == 1)
        return 0;
    else if (type == 2)
        return 0;
    else if (type == 3)
        return 0;
    else if (type == 4)
        return 0;
    else
        return 0;
}
