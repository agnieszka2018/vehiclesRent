cmake_minimum_required(VERSION 3.10)
project(pobiz01)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/model)


SET(SOURCE_FILES
        #pobiz01
        include/model/client/Address.h
        include/model/client/Client.h
        src/model/client/Client.cpp
        main.cpp
        src/model/client/Address.cpp
        src/model/rent/Rent.cpp
        include/model/rent/Rent.h
        include/model/vehicle/Vehicle.h
        src/model/vehicle/Vehicle.cpp
        src/model/vehicle/MotorVehicle.cpp
        include/model/vehicle/MotorVehicle.h
        src/model/vehicle/Car.cpp
        include/model/vehicle/Car.h
        src/model/vehicle/Mope.cpp
        include/model/vehicle/Mope.h
        src/model/vehicle/Bicycle.cpp
        include/model/vehicle/Bicycle.h
        src/model/repositories/RentsRepository.cpp
        include/model/repositories/RentsRepository.h
        include/model/repositories/VehicleRepository.h
        src/model/repositories/VehicleRepository.cpp
        include/model/client/ClientType.h
        src/model/client/ClientType.cpp
        src/model/client/RegularType.cpp
        include/model/client/RegularType.h
        src/model/client/BusinessType.cpp
        include/model/client/BusinessType.h
        src/model/client/VipType.cpp
        include/model/client/VipType.h
        src/model/repositories/ClientRepository.cpp
        include/model/repositories/ClientRepository.h
        include/model/manegers/RentsManager.h
        src/model/managers/RentsManager.cpp
        src/model/exceptions/ClientException.cpp
        include/model/exceptions/ClientException.h
        include/model/exceptions/RentException.h
        src/model/exceptions/RentException.cpp
        src/model/exceptions/VehicleException.cpp
        include/model/exceptions/VehicleException.h
        include/model/exceptions/DiscountException.h
        src/model/exceptions/DiscountException.cpp
        src/model/managers/ClientsManager.cpp
        src/model/managers/VehiclesManager.cpp
        include/model/manegers/VehiclesManager.h
        include/model/manegers/ClientsManager.h
        include/model/repositories/Repository.h
        include/model/searchEngine/SearchEngine.h
        src/model/searchEngine/SearchEngine.cpp)

add_library(biblioteka ${SOURCE_FILES})

add_executable(pobiz01 ${SOURCE_FILES})

#testy

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/model
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/TestRent.cpp
        test/TestClient.cpp
        test/TestVehicle.cpp
        test/TestRentsManager.cpp
        test/TestVehiclesManager.cpp
        test/TestClientsManager.cpp
        test/TestVehicleRepository.cpp
        test/TestRentsRepository.cpp
        test/TestAddress.cpp test/TestClientRepository.cpp)

add_executable (AllTests ${SOURCE_TEST_FILES})

target_link_libraries (AllTests
        biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_test(TestBiblioteki AllTests
        --report_level=detailed
        --log_level=all
        --color_output=yes)