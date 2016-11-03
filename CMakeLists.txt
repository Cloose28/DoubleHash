cmake_minimum_required(VERSION 3.6)
project(doubleHash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DoubleHashTable.cpp)
add_executable(doubleHash ${SOURCE_FILES})