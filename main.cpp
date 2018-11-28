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

    //Car *samochod = new Car("C", 100, "CW 84062", 2900);
    boost::shared_ptr<Car> samochod(new Car("C", 100, "CW 84062", 2900));
    boost::shared_ptr<Car> fiat(new Car("A", 80, "CW 11162", 900));
    boost::shared_ptr<Car> volvo(new Car("B", 150, "WK 67890", 1400));
    boost::shared_ptr<Car> porsche(new Car("D", 275, "WL 12345", 3500));
    boost::shared_ptr<Mope> skuter(new Mope(100, "CW 34342", 1200));
    boost::shared_ptr<Mope> vespa(new Mope(120, "WW 88842", 800));
    boost::shared_ptr<Mope> osa(new Mope(90, "CW 99942", 1000));
    boost::shared_ptr<Mope> piaggio(new Mope(95, "WE 222842", 900));
    boost::shared_ptr<Bicycle> rower(new Bicycle(50, "id_roweru"));
    boost::shared_ptr<Bicycle> damka(new Bicycle(60, "id_damki"));

    //repozytorium pojazdów
    boost::shared_ptr<VehicleRepository> repozytoriumPojazdow(new VehicleRepository());
    repozytoriumPojazdow->createVehicle(samochod.get());
    repozytoriumPojazdow->createVehicle(volvo.get());
    repozytoriumPojazdow->createVehicle(fiat.get());
    repozytoriumPojazdow->createVehicle(porsche.get());
    repozytoriumPojazdow->createVehicle(skuter.get());
    repozytoriumPojazdow->createVehicle(vespa.get());
    repozytoriumPojazdow->createVehicle(piaggio.get());
    repozytoriumPojazdow->createVehicle(osa.get());
    repozytoriumPojazdow->createVehicle(rower.get());
    repozytoriumPojazdow->createVehicle(damka.get());

    cout << "\n-> Raport dostępnych pojazdów w repozytorium: \n" << repozytoriumPojazdow->vehicleReport();

}