cmake_minimum_required(VERSION 3.2)
project(examples)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(std_vector_sharedptr ${SOURCE_FILES})