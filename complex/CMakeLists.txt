cmake_minimum_required(VERSION 3.5)
project(complex)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Complex.cpp)
add_executable(complex ${SOURCE_FILES} Complex.cpp)