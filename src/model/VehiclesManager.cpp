//
// Created by pobi on 05.12.18.
//

#include "VehiclesManager.h"

void VehiclesManager::addVehicleToRepository(VehicleRepoPtr vehicleRepo, VehiclePtr vehicle) {

    bool duplicate = false;

    std::list<VehiclePtr> vehicleRepoList = vehicleRepo->getVehicles();

    std::list<VehiclePtr>::iterator iter;
    for (iter = vehicleRepoList.begin(); iter != vehicleRepoList.end(); iter++) {
        //sprawdź czy nie ma już takiego pojazdu w Repozytorium Pojazdów
        if ((**iter) == (*vehicle))
            duplicate = true;
    }

    //wyjątek
    if (duplicate == true) {
        throw VehicleException("Pojazd już istnieje w Repozytorium Pojazdów!");
    }

    //dodawanie pojazdu do Repozytorium Pojazdów, jeśli nie ma jeszcze takiego w Repo
    vehicleRepo->createVehicle(vehicle);

}


void VehiclesManager::deleteVehicleFromRepository(VehicleRepoPtr vehicleRepo, VehiclePtr vehicle) {

    vehicleRepo->removeVehicle(vehicle);
}

