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

    currentRentsRepository *repozytoriumWypozyczen = new currentRentsRepository();

    Address *actuall_address = new Address("Mickiewicza", "7");
    //Vehicle *pojazd = new Vehicle(142, "cw12312", 0);
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
    //cout<<pojazd->vehicleInfo();


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


    posix_time::ptime pt(date(2018, Oct, 26), posix_time::hours(12));
    time_zone_ptr zone(new posix_time_zone("UTC+1"));
    local_date_time ldt(pt, zone);

    Client *klient_1 = new Client("Stefan", "Stonoga", "1029384756", actuall_address, nullptr, nullptr);

    //repozytozium wypożyczeń
    Rent *wypozyczenie = new Rent(ldt, skuter, klient_1);
    Rent *wypozyczenie_1 = new Rent(ldt, samochod, klient_1);

    repozytoriumWypozyczen->createRent(wypozyczenie, repozytoriumPojazdow);
    repozytoriumWypozyczen->createRent(wypozyczenie_1, repozytoriumPojazdow);
    cout << "\nUtworzono dwa wpożyczenia. \n" << endl;
    cout << "Sprawdzam kto wypożyczył skuter: " << endl;
    cout << repozytoriumWypozyczen->getClientForRentedVehicle(skuter);
    cout << "Już wiem, kto wypożyczył" << endl << endl;

    cout << "\n-> ~~~~~~~~~~~~~~~~~~~~~~Raport wypożyczeń: \n" << repozytoriumWypozyczen->rentReport();
    cout << "\n-> ~~~~~~~~~~~~~~~~~~~~~~Raport dostępnych pojazdów w repozytorium: \n"
         << repozytoriumPojazdow->vehicleReport();
    cout << "\nKończę jedno wypożyczenie: \n";
    repozytoriumWypozyczen->removeRent(wypozyczenie, repozytoriumPojazdow);
    cout << "\n-> ~~~~~~~~~~~~~~~~~~~~~~Raport wypożyczeń po oddaniu pojazdu: \n"
         << repozytoriumWypozyczen->rentReport();
    cout << "\n-> ~~~~~~~~~~~~~~~~~~~~~~Raport dostępnych pojazdów w repozytorium po oddaniu pojazdu: \n"
         << repozytoriumPojazdow->vehicleReport();



    //znajdz pojazd w repozytorium pojazdów na podstawie Id:
    //cout << "\nPodaj id, pojazdu, który ma być udostępniony: \n" << endl;
    //std::string podajId;
    //Vehicle *szukany = repozytoriumPojazdow->udostepnijPojazd("CW 34342");
    //cout << "OK, zapisałem wskaźnik do tego pojazdu!";
    //cout << "\nSzukałeś następującego pojazdu: " << szukany->vehicleInfo(); /*nie obsłużony przypadek, gdy nie ma pojazdu w repozytoriumPojazdów*/


    //znajdz pojazd na podstawie numeru indeksu
    cout << "\nPodaj numer indeksu pojazdu z repozytorium: " << endl;
    int number;
    cin >> number;
    Vehicle *poszukiwany = repozytoriumPojazdow->findVehicle(number);
    cout << "\nSzukałeś następującego pojazdu: " << poszukiwany->vehicleInfo();


    klient_1->modifyRent(wypozyczenie);
    //cout<<klient_1->clientInfo();

    actuall_address->changeInfo("Promienna", "5");
    cout << "\nAdres  zamieszkania po zmianie: " << klient_1->clientInfo();

    //cout<<"Info o client:\n"<<klient_1->clientInfo()<<endl<<endl;
    //cout<<"info o rent:"<<wypozyczenie->rentInfo()<<endl<<endl;

    cout << "\nOddanie pojazdu" << endl;
    wypozyczenie->returnVehicle();

    delete actuall_address;
    delete wypozyczenie;
    delete wypozyczenie_1;
    delete klient_1;
    delete samochod;
    delete skuter;
    delete repozytoriumWypozyczen;
    delete repozytoriumPojazdow;
    //delete szukany;
}