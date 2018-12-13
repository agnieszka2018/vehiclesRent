//
// Created by pobi on 06.12.18.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Client.h"
#include "Car.h"
#include "RegularType.h"
#include "Address.h"
#include "Rent.h"

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


BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientConstructorCase) {
        //data
        std::shared_ptr<RegularType> regulartype = std::make_shared<RegularType>();
        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");
        ClientPtr klient_3 = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype, actuallAddress,
                                                      actuallRegAddress);

        //test
        BOOST_REQUIRE_EQUAL("Stefan", klient_3->getFirstName());
        BOOST_REQUIRE_EQUAL(regulartype, klient_3->getClientType());
        BOOST_REQUIRE_EQUAL(actuallAddress, klient_3->getAddress());
        BOOST_REQUIRE_EQUAL(actuallRegAddress, klient_3->getRegisteredAddress());

    }

    BOOST_AUTO_TEST_CASE(ClientRentCase) {
        //data
        std::shared_ptr<RegularType> regulartype = std::make_shared<RegularType>();
        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");
        ClientPtr klient_3 = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype, actuallAddress,
                                                      actuallRegAddress);

        CarPtr pojazd = std::make_shared<Car>("C", 100, "CW 84062", 1995);
        CarPtr volvo = std::make_shared<Car>("B", 150, "WK 67890", 1400);

        boost::posix_time::ptime pt(date(2018, Dec, 6), boost::posix_time::hours(12));
        time_zone_ptr zone(new posix_time_zone("UTC+1"));
        local_date_time ldt(pt, zone);

        RentPtr wypozyczenie = std::make_shared<Rent>(ldt, pojazd, klient_3);
        RentPtr wypozyczenie_2 = std::make_shared<Rent>(ldt, volvo, klient_3);

        klient_3->addRent(wypozyczenie);
        klient_3->addRent(wypozyczenie_2);
        std::vector<RentPtr> actuallRents = klient_3->getClientActuallRents();

        //test
        BOOST_REQUIRE_EQUAL(2, actuallRents.size());    //oba pojazdy zostały dodane
        BOOST_REQUIRE_EQUAL(wypozyczenie_2, actuallRents.back());

        klient_3->deleteRent(wypozyczenie);   //oddaje pojazd
        actuallRents = klient_3->getClientActuallRents();
        BOOST_REQUIRE_EQUAL(wypozyczenie_2, actuallRents.back());

    }

BOOST_AUTO_TEST_SUITE_END()