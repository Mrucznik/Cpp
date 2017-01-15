cmake_minimum_required(VERSION 3.6)
project(tablica_asocjacyjna_wzorzec)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Map.cpp Map.h Employee.cpp Employee.h Book.cpp Book.h)
add_executable(tablica_asocjacyjna_wzorzec ${SOURCE_FILES})