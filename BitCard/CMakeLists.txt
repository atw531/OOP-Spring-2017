cmake_minimum_required(VERSION 3.8)
project(BitCard)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BitCard.cpp BitCard.hpp)
add_executable(BitCard ${SOURCE_FILES})