//
// Created by pobi on 04.12.18.
//

#ifndef POBIZ01_DISCOUNTEXCEPTION_H
#define POBIZ01_DISCOUNTEXCEPTION_H

#include <stdexcept>
#include <string>

class DiscountException : public std::logic_error {
public:
    std::string message;
    DiscountException(std::string);
};

#endif //POBIZ01_DISCOUNTEXCEPTION_H
