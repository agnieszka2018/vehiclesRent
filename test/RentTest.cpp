//
// Created by pobi on 01.11.18.
//

#include <boost/test/unit_test.hpp>

#include <chrono>
#include <thread>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "model/Rent.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "Car.h"

using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::uuids;

BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE(RentTimeDurationCase) {
            Address *actuall_address = new Address("Mickiewicza", "7");

        Car *pojazd = new Car(100, "CW 84062", 1995, "C");

            boost::posix_time::ptime pt(date(2018, Oct, 26), boost::posix_time::hours(12));
            time_zone_ptr zone(new posix_time_zone("UTC+1"));
            local_date_time ldt(pt, zone);

            Client *klient_3 = new Client("Stefan", "Stonoga", "1029384756", actuall_address, nullptr, nullptr);

            Rent *wypozyczenie = new Rent(ldt, pojazd, klient_3);

            klient_3->modifyRent(wypozyczenie);

            BOOST_REQUIRE_EQUAL(wypozyczenie, klient_3->getActuallRent());

            BOOST_REQUIRE_EQUAL(wypozyczenie->rentDuration(), 0);

            wypozyczenie->returnVehicle();
            BOOST_REQUIRE_GT(wypozyczenie->rentDuration(), 0);

    }
    BOOST_AUTO_TEST_SUITE_END()