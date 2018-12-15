//
// Created by pobi on 08.11.18.
//

#include "Car.h"

Car::~Car() {
    std::cout << "Destruktor Car" << std::endl;
}

const std::string &Car::getSegment() const {
    return segment;
}

Car::Car(std::string segment, int baseRentPrice, std::string id, int engineDisplacement) :
segment{segment}, MotorVehicle(baseRentPrice, id, engineDisplacement, calculateActualRentalPrice(baseRentPrice, engineDisplacement, segment))
{
    this->actuallRentalPrice = calculateActualRentalPrice(baseRentPrice, engineDisplacement, segment);
}


double Car::calculateActualRentalPrice(int baseRentPrice, int engineDisplacement, std::string segment) {

    double displacementMod = 0;

    if (engineDisplacement < 1000) displacementMod = 1.0;

    else if (engineDisplacement >= 1000 && engineDisplacement <= 2000)

        displacementMod = ( 0.5 * (engineDisplacement - 1000)) / 1000 + 1.0;

    else if (engineDisplacement > 2000) displacementMod = 1.5;

    if (segment == "A") return baseRentPrice * 1.0 * displacementMod;
    if (segment == "B") return baseRentPrice * 1.1 * displacementMod;
    if (segment == "C") return baseRentPrice * 1.2 * displacementMod;
    if (segment == "D") return baseRentPrice * 1.3 * displacementMod;
    if (segment == "E") return baseRentPrice * 1.5 * displacementMod;
    else return 0;           //samochod musi miec przyporzadkowany segment!

}


std::string Car::vehicleInfo() {
    std::string info = "\ncena podstawowa samochodu za dobę: " + std::to_string(getBaseRentPrice()) + "\n";
    info += "cena wlasciwa samochodu za dobę: " + std::to_string(actuallRentalPrice) + "\n";
    info += "id samochodu: " + getId() + "\n";
    info += "segment samochodu: " + segment + "\n";
    info += "pojemność silnika w samochodzie: " + std::to_string(getEngineDisplacement()) + "\n";
    return info;
}
