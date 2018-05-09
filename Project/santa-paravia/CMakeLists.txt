cmake_minimum_required(VERSION 3.8)
project(santa_paravia)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.hpp Player.cpp Player.hpp City.cpp City.hpp RevenueStream.hpp RandomGenerator.cpp RandomGenerator.hpp Resource.hpp Building.hpp Citizen.hpp)
add_executable(santa_paravia ${SOURCE_FILES})