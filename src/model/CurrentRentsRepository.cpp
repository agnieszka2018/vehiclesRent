//
// Created by pobi on 09.11.18.
//

#include <model/CurrentRentsRepository.h>

#include "CurrentRentsRepository.h"

void currentRentsRepository::createRent(Rent* rent) {
 rents.push_back(rent);
}

void currentRentsRepository::removeRent(Rent* rent) {

}

std::string currentRentsRepository::rentReport() {
    std::string info;
    info += "lista wypozyczen: \n";
    for (Rent *rent:rents) {
        std::cout << rent->rentInfo() << '\n';
    }
    std::cout<<"koniec listy\n";
    return " ";
}
