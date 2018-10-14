cmake_minimum_required(VERSION 3.10)
project(zajecia_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(zajecia_2 include/model/Client.h src/model/Client.cpp program.cpp include/model/Address.h)