cmake_minimum_required(VERSION 3.10)
project(pobiz01)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/model)


SET(SOURCE_FILES
        pobiz01
        include/model/Address.h
        include/model/Client.h
        src/model/Client.cpp
        main.cpp
        src/model/Address.cpp
        src/model/Rent.cpp
        include/model/Rent.h
        include/model/Vehicle.h
        src/model/Vehicle.cpp)

add_library(biblioteka ${SOURCE_FILES})

add_executable(pobiz01
        include/model/Address.h
        include/model/Client.h
        src/model/Client.cpp
        main.cpp
        src/model/Address.cpp
        src/model/Rent.cpp
        include/model/Rent.h
        include/model/Vehicle.h
        src/model/Vehicle.cpp)

#testy

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/model
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_RENT_FILES
        test/master.cpp
        test/RentTest.cpp)

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