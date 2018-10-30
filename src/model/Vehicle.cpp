//
// Created by pobi on 29.10.18.
//
#include <../../include/model/Vehicle.h>
#include <string>

using namespace std;

Vehicle::Vehicle(int baseRentPrice, string id) : baseRentPrice{baseRentPrice}, id{id}
{

}

/*Vehicle::Vehicle(std::string id) : id{id}
{
    baseRentPrice = 100;
} */

std::string Vehicle::vehicleInfo()
{
    string info = "\ncena: " + to_string(baseRentPrice) + "\nid: " + id + "\n";
    return info;
}