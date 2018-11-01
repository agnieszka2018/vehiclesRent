//
// Created by pobi on 29.10.18.
//
#include <../../include/model/Vehicle.h>
#include <string>

using namespace std;

Vehicle::Vehicle(int baseRentPrice, string id) : baseRentPrice{baseRentPrice}, id{id} {

}

/*Vehicle::Vehicle(std::string id) : id{id}
{
    baseRentPrice = 100;
} */

string Vehicle::vehicleInfo() {
    string info = "\ncena podstawowa: " + to_string(baseRentPrice) + "\nid: " + id + "\n";
    return info;
}

const int Vehicle::getBaseRentPrice() const {
    return baseRentPrice;
}
