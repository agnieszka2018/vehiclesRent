//
// Created by pobi on 22.11.18.
//

#ifndef POBIZ01_CLIENTTYPE_H
#define POBIZ01_CLIENTTYPE_H


class ClientType {
    const int maxRentedCarAmount;
    int clientTypeDiscount;
protected:
    ClientType(const int maxRentedCarAmount, int clientTypeDiscount);
    virtual double calculateClientTypeDiscount();
public:
    const int getMaxRentedCarAmount() const;
    int getClientTypeDiscount() const;

};

#endif //POBIZ01_CLIENTTYPE_H
