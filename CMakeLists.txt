cmake_minimum_required(VERSION 3.3)
project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/opt/cpp-netlib-0.11.2-final /opt/boost_1_60_0)
link_directories(/opt/boost_1_60_0/stage/lib)
link_libraries(boost_system)

set(SOURCE_FILES main.cpp)
add_executable(aws ${SOURCE_FILES})