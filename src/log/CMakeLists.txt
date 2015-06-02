cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES
Log.cpp
)

add_library(aws_log SHARED ${SOURCE_FILES})