cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

include_directories(../../src/socket /DevRes/Frameworks/boost_1_58_0/)
link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib/static)
link_libraries(asyncsocket boost_system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(aws_using_acceptor ${SOURCE_FILES})