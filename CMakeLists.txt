cmake_minimum_required(VERSION 3.10)
project(pobiz01)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/model)


SET(SOURCE_FILES
        #pobiz01
        include/model/Address.h
        include/model/Client.h
        src/model/Client.cpp
        main.cpp
        src/model/Address.cpp
        src/model/Rent.cpp
        include/model/Rent.h
        include/model/Vehicle.h
        src/model/Vehicle.cpp
        src/model/MotorVehicle.cpp
        include/model/MotorVehicle.h
        src/model/Car.cpp
        include/model/Car.h
        src/model/Mope.cpp
        include/model/Mope.h
        src/model/Bicycle.cpp
        include/model/Bicycle.h src/model/RentsRepository.cpp include/model/RentsRepository.h include/model/VehicleRepository.h src/model/VehicleRepository.cpp include/model/ClientType.h src/model/ClientType.cpp src/model/RegularType.cpp include/model/RegularType.h src/model/BusinessType.cpp include/model/BusinessType.h src/model/VipType.cpp include/model/VipType.h src/model/ClientRepository.cpp include/model/ClientRepository.h include/model/RentsManager.h src/model/RentsManager.cpp src/model/ClientException.cpp include/model/ClientException.h include/model/RentException.h src/model/RentException.cpp src/model/Interface.cpp include/model/Interface.h src/model/VehicleException.cpp include/model/VehicleException.h include/model/DiscountException.h src/model/DiscountException.cpp)

add_library(biblioteka ${SOURCE_FILES} src/model/VehicleRepository.cpp src/model/ClientType.cpp src/model/RentsManager.cpp src/model/ClientException.cpp src/model/RentException.cpp src/model/Interface.cpp src/model/VehicleException.cpp src/model/DiscountException.cpp)

add_executable(pobiz01
        ${SOURCE_FILES})

#testy

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/model
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_RENT_FILES
        test/master.cpp
        test/RentTest.cpp src/model/MotorVehicle.cpp include/model/MotorVehicle.h src/model/Car.cpp include/model/Car.h src/model/Mope.cpp include/model/Mope.h src/model/Bicycle.cpp include/model/Bicycle.h src/model/RentsRepository.cpp include/model/RentsRepository.h include/model/VehicleRepository.h src/model/VehicleRepository.cpp include/model/ClientType.h src/model/ClientType.cpp src/model/RegularType.cpp include/model/RegularType.h src/model/BusinessType.cpp include/model/BusinessType.h src/model/VipType.cpp include/model/VipType.h src/model/ClientRepository.cpp include/model/ClientRepository.h include/model/RentsManager.h src/model/RentsManager.cpp src/model/ClientException.cpp include/model/ClientException.h include/model/RentException.h src/model/RentException.cpp src/model/Interface.cpp include/model/Interface.h src/model/VehicleException.cpp include/model/VehicleException.h include/model/DiscountException.h src/model/DiscountException.cpp)

add_executable (TestRent ${SOURCE_TEST_RENT_FILES})

target_link_libraries (TestRent
        biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_test(TestBiblioteki RentTest
        --report_level=detailed
        --log_level=all
        --color_output=yes)