cmake_minimum_required(VERSION 2.8)
SET(PROJECT_NAME vector_compare_pro)
project(${PROJECT_NAME})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
SET(CMAKE_BUILD_TYPE Release)

add_executable(vector_compare ./main.cpp)

