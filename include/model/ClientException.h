//
// Created by pobi on 03.12.18.
//

#ifndef POBIZ01_CLIENTEXCEPTION_H
#define POBIZ01_CLIENTEXCEPTION_H

#include <stdexcept>
#include <string>

class ClientException : public std::logic_error {
public:
    std::string message;
    ClientException(std::string);
};

#endif //POBIZ01_CLIENTEXCEPTION_H
