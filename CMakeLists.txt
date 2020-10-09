cmake_minimum_required(VERSION 3.17)
project(Lab_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(StateRover StateRover.cpp
                          ReflexAgent.hpp
                          ReflexAgent.cpp
                          RoverSensors.hh
                          RoverSensors.cc)