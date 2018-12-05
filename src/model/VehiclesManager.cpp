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
        if ((((*iter)->getId()) == (vehicle->getId())) &&
        (((*iter)->getBaseRentPrice()) == (vehicle->getBaseRentPrice()))
        && (((*iter)->getActuallRentalPrice()) == (vehicle->getActuallRentalPrice())))
        duplicate = true; //jeśli spełnione wszystkie warunki jednocześnie, to znaczy, że jest to dokładnie ten sam pojazd!
    }

    try {
        if (duplicate == true) {
            VehicleException duplicatedVehicle("Pojazd już istnieje w Repozytorium Pojazdów!");
            throw duplicatedVehicle;
        }
    } catch (VehicleException duplicatedVeh) {
        std::cout << duplicatedVeh.what();
    }

    //dodawanie pojazdu do Repozytorium Pojazdów, jeśli nie ma jeszcze takiego w Repo
    vehicleRepo->createVehicle(vehicle);

}


void VehiclesManager::deleteVehicleFromRepository(VehicleRepoPtr vehicleRepo, VehiclePtr vehicle) {

vehicleRepo->removeVehicle(vehicle);}

