cmake_minimum_required(VERSION 3.6)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)
find_package(Boost)

set(SOURCE_FILES main.cpp)
add_executable(untitled2 ${SOURCE_FILES} Utils.h)