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
#include "RentsRepository.h"
#include "VehicleRepository.h"
#include "ClientType.h"
#include "RegularType.h"

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

//typedef boost::shared_ptr<dst_calc_rules> local_time::dst_calc_rule_ptr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Mope> MopePtr;
typedef std::shared_ptr<Bicycle> BicyclePtr;

int main() {

    //Car *samochod = new Car("C", 100, "CW 84062", 2900);
    CarPtr samochod = make_shared <Car>("C", 100, "CW 84062", 2900);
    CarPtr fiat = make_shared <Car> ("A", 80, "CW 11162", 900);
    CarPtr volvo = make_shared <Car> ("B", 150, "WK 67890", 1400);
    CarPtr porsche = make_shared <Car> ("D", 275, "WL 12345", 3500);
    MopePtr skuter = make_shared <Mope> (100, "CW 34342", 1200);
    MopePtr vespa = make_shared <Mope> (120, "WW 88842", 800);
    MopePtr osa = make_shared <Mope> (90, "CW 99942", 1000);
    MopePtr piaggio = make_shared <Mope> (95, "WE 222842", 900);
    BicyclePtr rower = make_shared <Bicycle> (50, "id_roweru");
    BicyclePtr damka = make_shared <Bicycle> (60, "id_damki");

    std::shared_ptr<RegularType> regulartype = make_shared <RegularType>();
    std::shared_ptr<Address> actuall_address = make_shared <Address>("Mickiewicza", "7");

    std::shared_ptr<Client> klient = make_shared<Client>("Stefan", "Stonoga", "1029384756", actuall_address.get(), nullptr, nullptr, regulartype.get());

    cout<<klient->clientInfo();

    //repozytorium pojazdów
    std::shared_ptr<VehicleRepository> repozytoriumPojazdow = make_shared<VehicleRepository>();
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