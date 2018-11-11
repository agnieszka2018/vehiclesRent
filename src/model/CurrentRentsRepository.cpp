//
// Created by pobi on 09.11.18.
//

#include <model/CurrentRentsRepository.h>
#include "Vehicle.h"
#include "CurrentRentsRepository.h"

using namespace std;

void currentRentsRepository::createRent(Rent* rent) {
    rents.push_back(rent);
}

void currentRentsRepository::removeRent(Rent* rent) {
    rents.remove(rent);
}

string currentRentsRepository::rentReport() {
    //string info;
    cout<< "lista wypozyczen: \n";
    for (Rent *rent:rents) {
        cout << rent->rentInfo() << '\n';
    }
    cout<<"koniec listy\n";
    return " ";
}


string currentRentsRepository::getClientForRentedVehicle(Vehicle * vehicle){
    return vehicle -> vehicleClientInfo();
}