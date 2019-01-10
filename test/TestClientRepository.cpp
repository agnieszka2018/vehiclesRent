//
// Created by pobi on 09.01.19.
//

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>
#include "list"
#include <memory>
#include "model/client/Client.h"
#include "model/repositories/ClientRepository.h"
#include "model/client/Address.h"
#include "model/client/RegularType.h"
#include "model/client/VipType.h"

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

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveClientCase) {


        //data
        RegularTypePtr regulartype = std::make_shared<RegularType>();
        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");
        ClientPtr klientStefan = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype,
                                                          actuallAddress,
                                                          actuallRegAddress);


        VipTypePtr viptype = std::make_shared<VipType>();
        AddressPtr actuallAddressOther = std::make_shared<Address>("Rudnickiego", "89");
        AddressPtr actuallRegAddressOther = std::make_shared<Address>("Kasprowicza", "14");
        ClientPtr klientZofia = std::make_shared<Client>("Zofia", "Kowalska", "9000084758", viptype,
                                                         actuallAddressOther,
                                                         actuallRegAddressOther);


        ClientRepository RepozytoriumKlientow;
        RepozytoriumKlientow.addClient(klientStefan);
        RepozytoriumKlientow.addClient(klientZofia);

        RepozytoriumKlientow.removeClient(klientStefan);    //została tylko klientka Zofia

        std::list<ClientPtr> listaKlientow = RepozytoriumKlientow.getClients();

        ClientPtr klientNowy = listaKlientow.back();

        BOOST_REQUIRE_EQUAL(klientNowy, klientZofia);

        RepozytoriumKlientow.removeClient(klientZofia);     //od teraz lista jest pusta

        listaKlientow = RepozytoriumKlientow.getClients();

        BOOST_REQUIRE_EQUAL(true, listaKlientow.empty());
    }


    BOOST_AUTO_TEST_CASE(ClientRepositoryModifyTypeCase) {
        //data
        RegularTypePtr regulartype = std::make_shared<RegularType>();
        AddressPtr actuallAddress = std::make_shared<Address>("Mickiewicza", "7");
        AddressPtr actuallRegAddress = std::make_shared<Address>("Redutowa", "744");
        ClientPtr klientStefan = std::make_shared<Client>("Stefan", "Stonoga", "1029384756", regulartype,
                                                          actuallAddress,
                                                          actuallRegAddress);


        VipTypePtr viptype = std::make_shared<VipType>();
        AddressPtr actuallAddressOther = std::make_shared<Address>("Rudnickiego", "89");
        AddressPtr actuallRegAddressOther = std::make_shared<Address>("Kasprowicza", "14");
        ClientPtr klientZofia = std::make_shared<Client>("Zofia", "Kowalska", "9000084758", viptype,
                                                         actuallAddressOther,
                                                         actuallRegAddressOther);


        ClientRepository RepozytoriumKlientow;
        RepozytoriumKlientow.addClient(klientStefan);
        RepozytoriumKlientow.addClient(klientZofia);

        RepozytoriumKlientow.modifyClientType(klientStefan, viptype);

        std::list<ClientPtr> listaKlientow = RepozytoriumKlientow.getClients();

        std::list<ClientPtr>::iterator iter;

        ClientTypePtr typ;

        for (iter = listaKlientow.begin(); iter != listaKlientow.end(); iter++) {
            if (*iter == klientStefan)
                typ = (*iter)->getClientType();
        }

        BOOST_REQUIRE_EQUAL(viptype, typ);
    }

BOOST_AUTO_TEST_SUITE_END()