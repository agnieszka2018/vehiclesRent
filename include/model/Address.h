//
// Created by pobi on 14.10.18.
//

#ifndef ZAJECIA_2_ADDRESS_H
#define ZAJECIA_2_ADDRESS_H

#include <string>

class Address {
private:
    std::string street;
    std::string number;

public:
    Address(std::string, std::string);

    void setAddress(std::string, std::string);

    std::string displayInfo();

    std::string getStreet();

    std::string getNumber();
};

#endif //ZAJECIA_2_ADDRESS_H


