//
// Created by pobi on 04.12.18.
//
#include "Interface.h"

std::string Interface::rentExceptionMessage() {
    //data
    AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
    AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");

    CarPtr pojazd = std::make_shared<Car>("C", 100, "CW 84062", 1995);

    boost::posix_time::ptime pt(date(2018, Oct, 26), boost::posix_time::hours(12));
    time_zone_ptr zone(new posix_time_zone("UTC+1"));
    local_date_time ldt(pt, zone);

    std::shared_ptr <RegularType> regulartype = std::make_shared<RegularType>();
    ClientPtr klient_3 = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype, actuallAddress,
                                                  actuallRegAddress);

    RentPtr wypozyczenie = std::make_shared<Rent>(ldt, pojazd, klient_3);

    VehicleRepoPtr repozytoriumPojazdow = std::make_shared<VehicleRepository>();

    RentsRepoPtr repozytoriumWypozyczen = std::make_shared<RentsRepository>();


    //checkig exception
    try {
        RentsManager manager;
        manager.rentVehicle(pojazd, klient_3, repozytoriumPojazdow, repozytoriumWypozyczen);
    }
    catch (RentException brakPoj) {
        cout << brakPoj.message << endl;
    }

    //return
}