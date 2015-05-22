cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/DevRes/Frameworks/boost_1_58_0/)

link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib)
link_libraries(boost_system)

set(SOURCE_FILES
ServerSocket.cpp
SocketAcceptor.cpp
Socket.cpp
OnServerSocketListener.h
Data.cpp
)

add_library(asyncsocket SHARED ${SOURCE_FILES})