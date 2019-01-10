//
// Created by pobi on 04.01.19.
//

#include <boost/test/unit_test.hpp>
#include <model/client/Address.h>


BOOST_AUTO_TEST_SUITE(AddressSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ChangeAddressCase) {

        Address actuallAddress("Mickiewicza", "7");
        Address actuallRegAddress("Redutowa", "744");

        actuallAddress.setAddress("Zamoyskiego", "88");

        BOOST_REQUIRE_EQUAL("Zamoyskiego", actuallAddress.getStreet());
        BOOST_REQUIRE_EQUAL("744", actuallRegAddress.getNumber());
    }

BOOST_AUTO_TEST_SUITE_END()