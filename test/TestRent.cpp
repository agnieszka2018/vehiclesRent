//
// Created by pobi on 01.11.18.
//

#include <boost/test/unit_test.hpp>

#include <chrono>
#include <thread>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "model/client/Client.h"
#include "model/client/Address.h"
#include "vehicle/Vehicle.h"
#include "model/rent/Rent.h"
#include "vehicle/Bicycle.h"
#include "vehicle/Car.h"
#include "vehicle/Mope.h"
#include "vehicle/MotorVehicle.h"
#include "model/repositories/RentsRepository.h"
#include "model/repositories/VehicleRepository.h"
#include "model/client/RegularType.h"

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Mope> MopePtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<RegularType> RegularTypePtr;


BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)


    BOOST_AUTO_TEST_CASE(RentTimeDurationCase) {
        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");

        CarPtr pojazd = std::make_shared<Car>("C", 100, "CW 84062", 1995);

        boost::posix_time::ptime pt(date(2018, Dec, 26), boost::posix_time::hours(12));
        time_zone_ptr zone(new posix_time_zone("UTC+1"));
        local_date_time ldt(pt, zone);

        std::shared_ptr<RegularType> regulartype = std::make_shared<RegularType>();

        ClientPtr klient_3 = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype, actuallAddress,
                                                      actuallRegAddress);

        RentPtr wypozyczenie = std::make_shared<Rent>(ldt, pojazd, klient_3);

        klient_3->addRent(wypozyczenie);
        std::vector<RentPtr> actuallRents = klient_3->getClientActuallRents();
        RentPtr fromVector = actuallRents.back();


        //test
        BOOST_REQUIRE_EQUAL(wypozyczenie, fromVector);

        BOOST_REQUIRE_EQUAL(wypozyczenie->rentDuration(), 0);   //przed oddaniem czas zawsze wynosi 0

        wypozyczenie->returnVehicle();
        BOOST_REQUIRE_GT(wypozyczenie->rentDuration(), 0);  //po oddaniu
    }


    BOOST_AUTO_TEST_CASE(VehicleRepositoryCase) {

        CarPtr samochod = std::make_shared<Car>("C", 100, "CW 84062", 2900);
        CarPtr volvo = std::make_shared<Car>("B", 150, "WK 67890", 1400);
        CarPtr fiat = std::make_shared<Car>("A", 80, "CW 11162", 900);
        CarPtr porsche = std::make_shared<Car>("D", 275, "WL 12345", 3500);
        BicyclePtr rower = std::make_shared<Bicycle>(50, "id_roweru");
        BicyclePtr damka = std::make_shared<Bicycle>(60, "id_damki");
        MopePtr skuter = std::make_shared<Mope>(100, "CW 34342", 1200);
        MopePtr vespa = std::make_shared<Mope>(120, "WW 88842", 800);
        MopePtr osa = std::make_shared<Mope>(90, "CW 99942", 1000);
        MopePtr piaggio = std::make_shared<Mope>(95, "WE 222842", 900);


        //repozytorium pojazdów
        VehicleRepoPtr repozytoriumPojazdow = std::make_shared<VehicleRepository>();
        repozytoriumPojazdow->createVehicle(rower);
        repozytoriumPojazdow->createVehicle(damka);
        repozytoriumPojazdow->createVehicle(samochod);
        repozytoriumPojazdow->createVehicle(volvo);
        repozytoriumPojazdow->createVehicle(fiat);
        repozytoriumPojazdow->createVehicle(porsche);
        repozytoriumPojazdow->createVehicle(skuter);
        repozytoriumPojazdow->createVehicle(vespa);
        repozytoriumPojazdow->createVehicle(osa);
        repozytoriumPojazdow->createVehicle(piaggio);



        //test: znajdz pojazd na podstawie numeru indeksu
        BOOST_REQUIRE_EQUAL(rower, repozytoriumPojazdow->findVehicle(1));
        BOOST_TEST_MESSAGE("Raport: " + repozytoriumPojazdow->vehicleReport());
    }


    BOOST_AUTO_TEST_CASE(CheckIfEqualCase) {

        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");

        CarPtr pojazd = std::make_shared<Car>("C", 100, "CW 84062", 1995);

        boost::posix_time::ptime pt(date(2018, Oct, 26), boost::posix_time::hours(12));
        time_zone_ptr zone(new posix_time_zone("UTC+1"));
        local_date_time ldt(pt, zone);

        std::shared_ptr<RegularType> regulartype = std::make_shared<RegularType>();

        ClientPtr klient_3 = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype, actuallAddress,
                                                      actuallRegAddress);

        Rent wypozyczenie(ldt, pojazd, klient_3);

        bool test = (wypozyczenie.operator==(wypozyczenie));

        BOOST_REQUIRE_EQUAL(true, test);    //sprawdzam czy dwa obiekty są sobie równe

    }

BOOST_AUTO_TEST_SUITE_END()