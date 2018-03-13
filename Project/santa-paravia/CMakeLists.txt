cmake_minimum_required(VERSION 3.8)
project(santa_paravia)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES SantaParavia.cpp Player.cpp Player.hpp Game.cpp Game.hpp City.cpp City.hpp)
add_executable(santa_paravia ${SOURCE_FILES})