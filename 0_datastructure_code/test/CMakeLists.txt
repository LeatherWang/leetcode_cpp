cmake_minimum_required(VERSION 2.8)
project(test)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_executable(test main.cpp)

