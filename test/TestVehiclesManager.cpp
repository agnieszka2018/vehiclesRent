//
// Created by pobi on 10.12.18.
//

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Vehicle.h"
#include "Bicycle.h"
#include "Car.h"
#include "Mope.h"
#include "MotorVehicle.h"
#include "VehicleRepository.h"
#include "VehiclesManager.h"

typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Mope> MopePtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;
typedef std::shared_ptr<VehicleRepository> VehicleRepoPtr;


BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    BOOST_AUTO_TEST_CASE(VehicleManagerDeleteVehicleCase) {

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

        std::list<VehiclePtr> listaPojazdow = repozytoriumPojazdow->getVehicles();
        size_t sizeBefore = listaPojazdow.size(); //rozmiar listy zawierającej pojazdy przed modyfikacjami


        VehiclesManager manager;
        manager.deleteVehicleFromRepository(repozytoriumPojazdow, rower);


        listaPojazdow = repozytoriumPojazdow->getVehicles();
        size_t sizeAfter = listaPojazdow.size(); //rozmiar listy zawierającej pojazdy po modyfikacjach

        BOOST_REQUIRE_GT(sizeBefore, sizeAfter);
    }

    BOOST_AUTO_TEST_CASE(VehicleManagerAddVehicleCase) {

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

        std::list<VehiclePtr> listaPojazdow = repozytoriumPojazdow->getVehicles();
        size_t sizeBefore = listaPojazdow.size(); //rozmiar listy zawierającej pojazdy przed modyfikacjami

        VehiclesManager manager;
        manager.addVehicleToRepository(repozytoriumPojazdow, piaggio);  //dodaje nie-duplikat do repozytorium

        listaPojazdow = repozytoriumPojazdow->getVehicles();
        size_t sizeAfter = listaPojazdow.size();

        BOOST_REQUIRE_LT(sizeBefore, sizeAfter);
    }

BOOST_AUTO_TEST_SUITE_END()