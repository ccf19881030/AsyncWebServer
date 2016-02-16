cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/opt/boost_1_58_0/ ../socket)

link_directories(/opt/boost_1_58_0/stage/lib/static)
link_libraries(boost_system async_socket)

set(SOURCE_FILES
Header.hpp
HttpFilter.cpp
Request.hpp
RequestParser.cpp
Reply.cpp
)

add_library(aws_http SHARED ${SOURCE_FILES})