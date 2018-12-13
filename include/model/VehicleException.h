//
// Created by pobi on 04.12.18.
//

#ifndef POBIZ01_VEHICLEEXCEPTION_H
#define POBIZ01_VEHICLEEXCEPTION_H

#include <string>
#include <stdexcept>
//#include <exception>

class VehicleException : public std::logic_error {
public:
    std::string message;

    VehicleException(std::string);
};

#endif //POBIZ01_VEHICLEEXCEPTION_H
