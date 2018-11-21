//
// Created by pobi on 14.10.18.
//

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

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

//typedef boost::shared_ptr<dst_calc_rules> local_time::dst_calc_rule_ptr;

int main() {

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

    cout << "\n-> Raport dostępnych pojazdów w repozytorium: \n" << repozytoriumPojazdow->vehicleReport();


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