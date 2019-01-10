//
// Created by pobi on 03.12.18.
//

#include "model/exceptions/RentException.h"

RentException::RentException(std::string message) : logic_error(message){}