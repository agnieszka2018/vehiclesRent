cmake_minimum_required(VERSION 3.10)
project(pobiz01)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/model)

add_executable(pobiz01
        include/model/Address.h
        include/model/Client.h
        src/model/Client.cpp
        main.cpp)
