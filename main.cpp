//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include "Client.h"
#include "Address.h"
#include "Vehicle.h"
#include "Rent.h"
#include "Bicycle.h"
#include "Car.h"
#include "Mope.h"
#include "MotorVehicle.h"

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

//typedef boost::shared_ptr<dst_calc_rules> local_time::dst_calc_rule_ptr;

int main() {
    Address *actuall_address = new Address("Mickiewicza", "7");
    //Vehicle *pojazd = new Vehicle(142, "cw12312", 0);
    Car *samochod = new Car(100, "CW 84062", 2900, "C");
    Mope *skuter = new Mope(100, "CW 34342", 1200);
    //cout<<pojazd->vehicleInfo();

    posix_time::ptime pt(date(2018,Oct,26), posix_time::hours(12));
    time_zone_ptr zone(new posix_time_zone("UTC+1"));
    local_date_time ldt(pt, zone);

    Client *klient_1 = new Client("Stefan", "Stonoga", "1029384756", actuall_address, nullptr, nullptr);

    Rent *wypozyczenie = new Rent(ldt, skuter, klient_1);

    klient_1->modifyRent(wypozyczenie);
    cout<<klient_1->clientInfo();

    actuall_address->changeInfo("Promienna", "5");

    cout << "\nAdres  zamieszkania po zmianie: " << klient_1->clientInfo();

    //cout<<"Info o client:\n"<<klient_1->clientInfo()<<endl<<endl;
    //cout<<"info o rent:"<<wypozyczenie->rentInfo()<<endl<<endl;

    wypozyczenie->returnVehicle();

    cout<<endl;

    delete actuall_address;
    delete wypozyczenie;
    delete klient_1;
    delete samochod;
    delete skuter;
}