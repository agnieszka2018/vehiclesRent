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
#include "Client.h"
#include "Address.h"
#include "Vehicle.h"
#include "Rent.h"
#include "Bicycle.h"
#include "Car.h"
#include "Mope.h"
#include "MotorVehicle.h"
#include "CurrentRentsRepository.h"
#include "VehicleRepository.h"

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;


BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentTimeDurationCase) {
        Address *actuall_address = new Address("Mickiewicza", "7");


        Car *pojazd = new Car("C", 100, "CW 84062", 1995);

        boost::posix_time::ptime pt(date(2018, Oct, 26), boost::posix_time::hours(12));
        time_zone_ptr zone(new posix_time_zone("UTC+1"));
        local_date_time ldt(pt, zone);
        

        Client *klient_3 = new Client("Stefan", "Stonoga", "1029384756", actuall_address, nullptr, nullptr, nullptr);

        Rent *wypozyczenie = new Rent(ldt, pojazd, klient_3);

        klient_3->modifyRent(wypozyczenie);

        BOOST_REQUIRE_EQUAL(wypozyczenie, klient_3->getActuallRent());

        BOOST_REQUIRE_EQUAL(wypozyczenie->rentDuration(), 0);

        wypozyczenie->returnVehicle();
        BOOST_REQUIRE_GT(wypozyczenie->rentDuration(), 0);

        delete pojazd;
        delete klient_3;
        delete wypozyczenie;
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryCase) {

        Car *samochod = new Car("C", 100, "CW 84062", 2900);
        Car *fiat = new Car("A", 80, "CW 11162", 900);
        Car *volvo = new Car("B", 150, "WK 67890", 1400);
        Car *porsche = new Car("D", 275, "WL 12345", 3500);
        Mope *skuter = new Mope(100, "CW 34342", 1200);
        Mope *vespa = new Mope(120, "WW 88842", 800);
        Mope *osa = new Mope(90, "CW 99942", 1000);
        Mope *piaggio = new Mope(95, "WE 222842", 900);
        Bicycle *rower = new Bicycle(50, "id_roweru");
        Bicycle *damka = new Bicycle(60, "id_damki");

        //repozytorium pojazdów
        VehicleRepository *repozytoriumPojazdow = new VehicleRepository();
        repozytoriumPojazdow->createVehicle(samochod);
        repozytoriumPojazdow->createVehicle(volvo);
        repozytoriumPojazdow->createVehicle(fiat);
        repozytoriumPojazdow->createVehicle(porsche);
        repozytoriumPojazdow->createVehicle(skuter);
        repozytoriumPojazdow->createVehicle(vespa);
        repozytoriumPojazdow->createVehicle(piaggio);
        repozytoriumPojazdow->createVehicle(osa);
        repozytoriumPojazdow->createVehicle(rower);
        repozytoriumPojazdow->createVehicle(damka);


        //znajdz pojazd na podstawie numeru indeksu
        BOOST_REQUIRE_EQUAL(samochod, repozytoriumPojazdow->findVehicle(1));

        delete repozytoriumPojazdow;
        delete damka;
        delete rower;
        delete piaggio;
        delete osa;
        delete vespa;
        delete skuter;
        delete porsche;
        delete volvo;
        delete fiat;
        delete samochod;
    }


    BOOST_AUTO_TEST_CASE(CurrentRentsRepositoryCase) {

        boost::posix_time::ptime pt(date(2018, Oct, 26), boost::posix_time::hours(12));
        time_zone_ptr zone(new posix_time_zone("UTC+1"));
        local_date_time ldt(pt, zone);

        Mope *skuter = new Mope(100, "CW 34342", 1200);
        Car *samochod = new Car("C", 100, "CW 84062", 2900);
        Car *fiat = new Car("A", 80, "CW 11162", 900);
        Car *volvo = new Car("B", 150, "WK 67890", 1400);

        Address *actuall_address = new Address("Mickiewicza", "7");

        Client *klient_1 = new Client("Stefan", "Stonoga", "1029384756", actuall_address, nullptr, nullptr, nullptr);

        Rent *wypozyczenie = new Rent(ldt, skuter, klient_1);
        Rent *wypozyczenie_1 = new Rent(ldt, samochod, klient_1);

        //repozytorium pojazdów
        VehicleRepository *repozytoriumPojazdow = new VehicleRepository();
        repozytoriumPojazdow->createVehicle(samochod);
        repozytoriumPojazdow->createVehicle(volvo);
        repozytoriumPojazdow->createVehicle(fiat);
        repozytoriumPojazdow->createVehicle(skuter);

        //repozytozium wypożyczeń
        currentRentsRepository *repozytoriumWypozyczen = new currentRentsRepository();
        repozytoriumWypozyczen->createRent(wypozyczenie, repozytoriumPojazdow);
        repozytoriumWypozyczen->createRent(wypozyczenie_1, repozytoriumPojazdow);


        // ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
        // test ile wypozyczeń w repozytoriumWypozyczen, a ile samochodów w repozytoriumPojazdow
        // test kto wypozyczył pojazd; cout << repozytoriumWypozyczen->getClientForRentedVehicle(skuter);
        // test raport z repozytoriumWypozyczen oraz repozytoriumPojazdow: przed i po oddaniu
        // test zmodyfikuj wypozyczenie


        delete repozytoriumWypozyczen;
        delete repozytoriumPojazdow;
        delete wypozyczenie_1;
        delete wypozyczenie;
        delete klient_1;
        delete actuall_address;
        delete volvo;
        delete fiat;
        delete samochod;
        delete skuter;
    }


BOOST_AUTO_TEST_SUITE_END()