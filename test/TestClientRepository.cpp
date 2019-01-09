//
// Created by pobi on 09.01.19.
//

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>
#include "list"
#include <memory>
#include "Client.h"
#include "ClientRepository.h"
#include "Address.h"
#include "RegularType.h"
#include "VipType.h"

typedef std::shared_ptr<ClientRepository> ClientRepoPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<RegularType> RegularTypePtr;
typedef std::shared_ptr<VipType> VipTypePtr;

BOOST_AUTO_TEST_SUITE(RentSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddClientCase) {

        //data
        RegularTypePtr regulartype = std::make_shared<RegularType>();
        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");
        ClientPtr klientStefan = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype,
                                                          actuallAddress,
                                                          actuallRegAddress);

        ClientRepository RepozytoriumKlientow;
        RepozytoriumKlientow.addClient(klientStefan);

        VipTypePtr viptype = std::make_shared<VipType>();
        AddressPtr actuallAddressOther = std::make_shared<Address>("Rudnickiego", "89");
        AddressPtr actuallRegAddressOther = std::make_shared<Address>("Kasprowicza", "14");
        ClientPtr klientZofia = std::make_shared<Client>("Zofia", "Kowalska", "9000084758", viptype,
                                                         actuallAddressOther,
                                                         actuallRegAddressOther);

        RepozytoriumKlientow.addClient(klientZofia);

        std::list<ClientPtr> klienci = RepozytoriumKlientow.getClients();
        int liczbaKlientow = klienci.size();

        BOOST_REQUIRE_EQUAL(2, liczbaKlientow);

    }


BOOST_AUTO_TEST_SUITE_END()