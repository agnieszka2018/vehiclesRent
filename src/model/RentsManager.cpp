//
// Created by pobi on 01.12.18.
//
#include <list>
#include "RentsManager.h"

RentsManager::RentsManager() {}

RentsManager::~RentsManager() {}


std::vector<RentPtr> RentsManager::getAllClientRents(ClientPtr client) {
    //pobiera wszystkie zakończone wypożyczenia klienta
    std::vector<RentPtr> finishedClientRents = client->getAllClientRents();
}

double RentsManager::checkClientRentBallance(ClientPtr client) {
    double priceWithDiscount;
    //pobieram wszystkie zakończone wypożyczenia klienta
    std::vector<RentPtr> allRents = getAllClientRents(client);
    std::vector<RentPtr>::iterator iter;
    for (iter = allRents.begin(); iter != allRents.end(); iter++) {
        priceWithDiscount += client->calculatePriceWithDiscount(*iter); //sumowana cena każdego wypożyczenia po uwzględnieniu rabatu
    }

    //int allFinishedClientRents = static_cast<int>(client->getAllClientRents().size());
    return priceWithDiscount;
}

void RentsManager::changeClientType(ClientPtr client) {
    //zmiana typu klienta w zależności od wydanych pieniędzy
    double clientBallance = checkClientRentBallance(client);

    if (clientBallance <= 1000) {
        RegularTypePtr regularType = std::make_shared<RegularType>();
        client->setClientType(regularType);
    } else if (clientBallance > 2000) {
        VipTypePtr vipType = std::make_shared<VipType>();
        client->setClientType(vipType);
    } else if (clientBallance > 1000) {
        BusinessTypePtr businessType = std::make_shared<BusinessType>();
        client->setClientType(businessType);
    }
}


void RentsManager::rentVehicle(VehiclePtr vehicle, ClientPtr client, VehicleRepoPtr vehicleRepo, RentsRepoPtr rentsRepo) {

    //sprawdź czy vehicle jest w VehicleRepository
    bool jest = false;

    std::list<VehiclePtr> vehicles = vehicleRepo->getVehicles();

    std::list<VehiclePtr>::iterator iter;
    for (iter = vehicles.begin(); iter != vehicles.end(); iter++) {
        if (vehicle == (*iter))
            jest = true;
        else jest = false;
    }

    //obsługa wyjątku (RentException) - brak pojazdu w VehicleRepository
    if (jest != true) {
        throw RentException("Brak pojazdu w Repozytorium Pojazdów");
    }



    //sprawdź czy klient nie wypożyczył za dużo
    int numberPossible = client->getClientType()->getMaxRentedCarAmount();    //liczba przysługujących wypożyczeń
    int numberActuall = static_cast<int>(client->getClientActuallRents().size());    //liczba aktualnych wypożyczeń


    //obsługa wyjątku (RentException) - klient wykorzystał limit samochodów, które może wypożyczyć jednocześnie
    try {
        if (numberActuall == numberPossible) {
            RentException limitWyczerpany("Klient wykorzystal limit jednocześnie wypożyczonych pojazdów");
            throw limitWyczerpany;
        }
    }
    catch (RentException limitWyczerpany) {
        std::cout << limitWyczerpany.what();
    }

    //utwórz wypożyczenie
    posix_time::ptime pt(date(2018, Dec, 02), posix_time::hours(12));
    time_zone_ptr zone(new posix_time_zone("UTC+1"));
    local_date_time ldt(pt, zone);

    RentPtr rent = std::make_shared<Rent>(ldt, vehicle, client);
    rentsRepo->createRent(rent, vehicleRepo);
    client->addRent(rent);   //dodajemy wypożyczenie 'rent' do aktualnej listy wypożyczeń klienta

}

void RentsManager::returnVehicle(ClientPtr client, RentsRepoPtr rentsRepo, RentPtr rent, VehicleRepoPtr vehicleRepo) {

    //usuwa klientowi wypożyczenie z listy aktualnych
    try { client->deleteRent(rent); }
    catch (ClientException noCar) {
        std::cout << noCar.what();
    }

    //przenosi wypożyczenie z curent do archive
    rentsRepo->removeRent(rent, vehicleRepo);

    //sprawdza bilans klienta i ewentualnie zmienia jego typ
    changeClientType(client);
}

