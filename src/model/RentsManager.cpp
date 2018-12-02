//
// Created by pobi on 01.12.18.
//
#include <list>
#include "RentsManager.h"

RentsManager::RentsManager() {}

RentsManager::~RentsManager() {}

void RentsManager::rentVehicle(Vehicle *vehicle, Client *client, VehicleRepository *vehicleRepo) {

    //sprawdź czy vehicle jest w rentsRepository
    bool jest;

    std::list<Vehicle *> vehicles = vehicleRepo->getVehicles();

    std::list<Vehicle *>::iterator iter;
    for (iter = vehicles.begin(); iter != vehicles.end(); iter++) {
        if (vehicle == *iter)
            jest = true;
        else jest = false;
    }

    //sprawdź czy klient nie wypożyczył za dużo
    int numberPossible = client->getClientType()->getMaxRentedCarAmount();    //liczba przysługujących wypożyczeń
    int numberActuall = client->getClientActuallRents().size();    //liczba aktualnych wypożyczeń

    if ((numberActuall < numberPossible) && (jest)) {
        //wypożycz pojazd
    }
}

void RentsManager::returnVehicle() {}

void RentsManager::getAllClientRents() {}

void RentsManager::checkClientRentBallance(Client *client) {}

void RentsManager::changeClientType() {}
