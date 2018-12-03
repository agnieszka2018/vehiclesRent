//
// Created by pobi on 01.12.18.
//
#include <list>
#include "RentsManager.h"

RentsManager::RentsManager() {}

RentsManager::~RentsManager() {}

void
RentsManager::rentVehicle(VehiclePtr vehicle, ClientPtr client, VehicleRepoPtr vehicleRepo, RentsRepoPtr rentsRepo) {

    //sprawdź czy vehicle jest w VehicleRepository
    bool jest = false;

    std::list<VehiclePtr> vehicles = vehicleRepo->getVehicles();

    std::list<VehiclePtr>::iterator iter;
    for (iter = vehicles.begin(); iter != vehicles.end(); iter++) {
        if (vehicle == *iter)
            jest = true;
        else jest = false;
    }

    //sprawdź czy klient nie wypożyczył za dużo
    int numberPossible = client->getClientType()->getMaxRentedCarAmount();    //liczba przysługujących wypożyczeń
    int numberActuall = static_cast<int>(client->getClientActuallRents().size());    //liczba aktualnych wypożyczeń

    if ((numberActuall < numberPossible) && (jest)) {

        posix_time::ptime pt(date(2018, Dec, 02), posix_time::hours(12));
        time_zone_ptr zone(new posix_time_zone("UTC+1"));
        local_date_time ldt(pt, zone);

        RentPtr rent = std::make_shared<Rent>(ldt, vehicle, client);
        rentsRepo->createRent(rent, vehicleRepo);
    }
}

void RentsManager::returnVehicle(ClientPtr client, RentsRepoPtr rentsRepo, RentPtr rent, VehicleRepoPtr vehicleRepo) {
    //usuwa klientowi wypożyczenie z listy aktualnych
    client->deleteRent(rent);

    //przenosi wypożyczenie z curent do archive
    rentsRepo->removeRent(rent, vehicleRepo);

    //zmiana typu klienta
    int allFinishedClientRents = static_cast<int>(client->getAllClientRents().size());
    if (allFinishedClientRents <= 5) {
        RegularTypePtr regularType = std::make_shared<RegularType>();
        client->setClientType(regularType);
    } else if (allFinishedClientRents > 5) {
        BusinessTypePtr businessType = std::make_shared<BusinessType>();
        client->setClientType(businessType);
    } else if (allFinishedClientRents > 10) {
        VipTypePtr vipType = std::make_shared<VipType>();
        client->setClientType(vipType);
    }
}

void RentsManager::getAllClientRents(ClientPtr client) {
    //pobiera wszystkie zakończone wypożyczenia klienta
    std::vector<RentPtr> finishedClientRents = client->getAllClientRents();
}

void RentsManager::checkClientRentBallance(ClientPtr client) {}

void RentsManager::changeClientType() {}
