
project(Rational CXX)

set(CMAKE_CXX_FLAGS "-std=c++1z")

add_library(Cards
  BitCard.cpp
  OOPCard.cpp
  UnionCard.cpp)

add_executable(AltCards 
  main.cpp)

target_link_libraries(AltCards Cards)