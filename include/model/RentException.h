//
// Created by pobi on 03.12.18.
//

#ifndef POBIZ01_RENTEXCEPTION_H
#define POBIZ01_RENTEXCEPTION_H

#include <stdexcept>
#include <string>

class RentException : public std::logic_error{
public:
    std::string message;
    RentException(std::string);
};

#endif //POBIZ01_RENTEXCEPTION_H
