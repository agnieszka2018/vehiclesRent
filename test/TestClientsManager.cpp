//
// Created by pobi on 10.12.18.
//

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <string>
#include <list>
#include <memory>
#include "model/client/Client.h"
#include "model/repositories/ClientRepository.h"
#include "model/client/Address.h"
#include "model/client/RegularType.h"
#include "model/client/VipType.h"
#include "model/manegers/ClientsManager.h"

typedef std::shared_ptr<ClientRepository> ClientRepoPtr;
typedef std::shared_ptr<Address> AddressPtr;
typedef std::shared_ptr<RegularType> RegularTypePtr;
typedef std::shared_ptr<VipType> VipTypePtr;
typedef std::shared_ptr<Client> ClientPtr;

BOOST_AUTO_TEST_SUITE(ClientSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientManagerAddClientCase) {


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


        ClientRepoPtr repozytoriumKlientow = std::make_shared<ClientRepository>();
        ClientsManager manager;


        manager.addClientToRepository(repozytoriumKlientow, klientStefan);  //dodaje klienta Stefana

        std::list<ClientPtr> listaKlientow = repozytoriumKlientow->getClients();
        size_t rozmiarListy = listaKlientow.size();

        BOOST_REQUIRE_EQUAL(1, rozmiarListy);


        manager.addClientToRepository(repozytoriumKlientow, klientZofia);   //dodaje klientke Zofie

        listaKlientow = repozytoriumKlientow->getClients();
        rozmiarListy = listaKlientow.size();

        BOOST_REQUIRE_EQUAL(2, rozmiarListy);

    }

    BOOST_AUTO_TEST_CASE(ClientManagerDeleteClientCase) {


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


        ClientRepoPtr repozytoriumKlientow = std::make_shared<ClientRepository>();
        repozytoriumKlientow->addClient(klientZofia);
        repozytoriumKlientow->addClient(klientStefan);

        std::list<ClientPtr> listaKlientow = repozytoriumKlientow->getClients();
        size_t rozmiarListy = listaKlientow.size();

        BOOST_REQUIRE_EQUAL(2, rozmiarListy);   //sprawdzam rozmiar listy klientów PRZED

        ClientsManager manager;
        manager.deleteClientFromRepository(repozytoriumKlientow, klientZofia);

        listaKlientow = repozytoriumKlientow->getClients();
        rozmiarListy = listaKlientow.size();

        BOOST_REQUIRE_EQUAL(1, rozmiarListy);   //sprawdzam rozmiar listy klientów PO usunięciu klienta Zofii

        manager.deleteClientFromRepository(repozytoriumKlientow, klientStefan);

        listaKlientow = repozytoriumKlientow->getClients();
        rozmiarListy = listaKlientow.size();

        BOOST_REQUIRE_EQUAL(0, rozmiarListy);   //sprawdzam rozmiar listy klientów PO usunięciu klienta Stefana
    }

BOOST_AUTO_TEST_SUITE_END()