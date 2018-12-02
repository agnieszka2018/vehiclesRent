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
    Address(std::string street, std::string number);

    void changeInfo(std::string ulica, std::string numer);

    std::string displayInfo();
};

#endif //ZAJECIA_2_ADDRESS_H

