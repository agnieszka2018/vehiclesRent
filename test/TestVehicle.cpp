//
// Created by pobi on 06.12.18.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "model/client/Client.h"
#include "vehicle/Car.h"
#include "model/client/RegularType.h"
#include "model/client/Address.h"
#include "model/rent/Rent.h"
#include "vehicle/Vehicle.h"

#include <chrono>
#include <thread>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

typedef std::shared_ptr<RegularType> RegularTypePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<Car> CarPtr;
typedef std::shared_ptr<Vehicle> VehiclePtr;


BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

BOOST_AUTO_TEST_CASE(VehicleBaseRentalPriceCase) {
        //data
        CarPtr fiat = std::make_shared<Car>("A", 80, "CW 11162", 900);

        //test
        BOOST_REQUIRE_EQUAL(80, fiat->getBaseRentPrice());  //cena bazowa
}

BOOST_AUTO_TEST_CASE(VehActRenPriCase) {
        //data
        CarPtr bugatti = std::make_shared<Car>("E", 100, "CW 11162", 3000);

        BOOST_REQUIRE_EQUAL(225, bugatti->calculateActualRentalPrice(100, 3000, "E"));
}

BOOST_AUTO_TEST_CASE(VehicleExceptionCase) {
        //data
        std::shared_ptr<RegularType> regulartype = std::make_shared<RegularType>();
        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");
        ClientPtr klient_3 = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype, actuallAddress,
        actuallRegAddress);


        VehiclePtr mustang = std::make_shared<Vehicle>(80, "CW 11162");
        BOOST_REQUIRE_EQUAL(mustang->getBaseRentPrice(), 80);

        // TODO test VehicleException napisać!
}

BOOST_AUTO_TEST_SUITE_END()