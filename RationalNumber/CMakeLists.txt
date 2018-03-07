
project(Rational CXX)

set(CMAKE_CXX_FLAGS "-std=c++1z")

add_library(RationalNumber
  RationalNumber.cpp)

add_executable(Rational 
  main.cpp)

target_link_libraries(Rational RationalNumber)