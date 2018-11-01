//
// Created by pobi on 01.11.18.
//
#include <boost/test/unit_test.hpp>
#include "Vehicle.h"
#include "Rent.h"
#include "Client.h"

using namespace std;
using namespace boost;
using namespace local_time;
using namespace gregorian;
using posix_time::time_duration;


BOOST_AUTO_TEST_SUITE()


    BOOST_AUTO_TEST_CASE(TestRentDuration) {

        Client *testClient = new Client("Alojzy", "Kowalski", "1029384756");
        Vehicle *testAuto = new Vehicle(120, "WK4567894");

        posix_time::ptime posTime(date(2018, Oct, 23), posix_time::hours(12));
        time_zone_ptr zone(new posix_time_zone("UTC+1"));
        local_date_time ldt(posTime, zone);

        Rent testRent(ldt, testAuto, testClient);

        BOOST_REQUIRE_EQUAL(testRent.rentDuration(), 0);

    }


BOOST_AUTO_TEST_SUITE_END()
