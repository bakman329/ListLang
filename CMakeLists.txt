cmake_minimum_required(VERSION 3.5)
project(Language)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp List.cpp List.h Options.cpp Options.h)
add_executable(Language ${SOURCE_FILES})