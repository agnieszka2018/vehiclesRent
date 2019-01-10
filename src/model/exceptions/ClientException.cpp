//
// Created by pobi on 03.12.18.
//
#include "model/exceptions/ClientException.h"

ClientException::ClientException(std::string message) : logic_error(message){}