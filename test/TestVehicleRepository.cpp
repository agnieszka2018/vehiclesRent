//
// Created by pobi on 14.12.18.
//

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "vehicle/Vehicle.h"
#include "vehicle/Bicycle.h"
#include "vehicle/Car.h"
#include "vehicle/Mope.h"
#include "vehicle/MotorVehicle.h"
#include "model/repositories/VehicleRepository.h"

typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Mope> MopePtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;


BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleRepositoryAddVehicleCase) {

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

        std::list<VehiclePtr> vehicles = repozytoriumPojazdow->getVehicles();
        size_t rozmiar = vehicles.size();

        BOOST_REQUIRE_EQUAL(10, rozmiar);
    }

    BOOST_AUTO_TEST_CASE(VehicleRepositoryDeleteVehicleCase) {

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


        std::list<VehiclePtr> vehicles = repozytoriumPojazdow->getVehicles();
        size_t rozmiar = vehicles.size();

        BOOST_REQUIRE_EQUAL(10, rozmiar);

        repozytoriumPojazdow->removeVehicle(piaggio);

        vehicles = repozytoriumPojazdow->getVehicles();
        rozmiar = vehicles.size();

        BOOST_REQUIRE_EQUAL(9, rozmiar);


        repozytoriumPojazdow->removeVehicle(volvo);
        repozytoriumPojazdow->removeVehicle(damka);

        vehicles = repozytoriumPojazdow->getVehicles();
        rozmiar = vehicles.size();

        BOOST_REQUIRE_EQUAL(7, rozmiar);
    }

BOOST_AUTO_TEST_SUITE_END()