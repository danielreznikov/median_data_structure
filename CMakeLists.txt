cmake_minimum_required(VERSION 3.7)
project(median)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Median.cpp Median.h median_tests.cpp)

add_executable(median ${SOURCE_FILES})