cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/opt/boost_1_58_0/ ../log)

link_directories(/opt/boost_1_58_0/stage/lib/static)
link_libraries(boost_system aws_log)

set(SOURCE_FILES
ServerSocket.cpp
SocketAcceptor.cpp
Connection.cpp
ConnectionManager.cpp
Filter.h
InputBufferMessage.cpp
Buffer.h
)

add_library(async_socket SHARED ${SOURCE_FILES})