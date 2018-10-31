//
// Created by pobi on 14.10.18.
//

#include <iostream>
#include "./include/model/Client.h"
#include "./include/model/Address.h"
#include "Vehicle.h"
#include "Rent.h"

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;

//typedef boost::shared_ptr<dst_calc_rules> local_time::dst_calc_rule_ptr;

int main() {
    Address *actuall_address = new Address("Mickiewicza", "7");
    Client klient_1("Jan", "Kowalski", "123456789", actuall_address);
    Client klient_2("Kamil", "Nowak", "987654321", actuall_address);

    cout << klient_1.clientInfo() << endl;
    cout << klient_2.clientInfo();

    //cout << "Adres  zamieszkania przed zmianą: " << klient_1.clientInfo();

    actuall_address->changeInfo("Promienna", "5");
    cout << "\nAdres  zamieszkania po zmianie: " << klient_1.clientInfo();
    cout << "\nAdres  zamieszkania po zmianie: " << klient_2.clientInfo() << endl;

    Vehicle *pojazd = new Vehicle(142, "cw12312");
    //cout<<pojazd->vehicleInfo();

    posix_time::ptime pt(date(2018,Oct,26), posix_time::hours(12));
    time_zone_ptr zone(new posix_time_zone("UTC+1"));
    local_date_time ldt(pt, zone);

    Client *klient_3 = new Client("Stefan", "Stonoga", "1029384756", actuall_address);

    Rent wypozyczenie(ldt, pojazd, klient_3);
    cout<<wypozyczenie.rentInfo()<<endl;
    wypozyczenie.returnVehicle();

    cout<<endl;

    delete actuall_address;
}