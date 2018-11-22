//
// Created by pobi on 22.11.18.
//

#ifndef POBIZ01_CLIENTTYPE_H
#define POBIZ01_CLIENTTYPE_H


class ClientType {
    const int maxVehicle;
    const int discount;

public:
    const int getMaxVehicle(int) const;

    const int getDiscount(int) const;
};

#endif //POBIZ01_CLIENTTYPE_H
