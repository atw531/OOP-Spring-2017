cmake_minimum_required(VERSION 3.8)
project(War)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Card.cpp Card.hpp)
add_executable(War ${SOURCE_FILES})