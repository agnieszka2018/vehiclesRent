//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include <string>
#include <memory>
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

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;


int main() {

    std::shared_ptr<Car> samochod = std::make_shared<Car>("C", 100, "CW 84062", 2900);
    std::shared_ptr<Car> fiat = std::make_shared<Car>("A", 80, "CW 11162", 900);
    std::shared_ptr<Car> volvo = std::make_shared<Car>("B", 150, "WK 67890", 1400);
    std::shared_ptr<Car> porsche = std::make_shared<Car>("D", 275, "WL 12345", 3500);
    std::shared_ptr<Mope> skuter = std::make_shared<Mope>(100, "CW 34342", 1200);
    std::shared_ptr<Mope> vespa = std::make_shared<Mope>(120, "WW 88842", 800);
    std::shared_ptr<Mope> osa = std::make_shared<Mope>(90, "CW 99942", 1000);
    std::shared_ptr<Mope> piaggio = std::make_shared<Mope>(95, "WE 222842", 900);
    std::shared_ptr<Bicycle> rower = std::make_shared<Bicycle>(50, "id_roweru");
    std::shared_ptr<Bicycle> damka = std::make_shared<Bicycle>(60, "id_damki");

    //repozytorium pojazdów
    std::shared_ptr<VehicleRepository> repozytoriumPojazdow = std::make_shared<VehicleRepository>();
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

    cout << "\n-> Raport dostępnych pojazdów w repozytorium: \n" << repozytoriumPojazdow->vehicleReport();

}