cmake_minimum_required(VERSION 3.6)
project(tablica_asocjacyjna)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Map.cpp Map.h)
add_executable(tablica_asocjacyjna ${SOURCE_FILES})