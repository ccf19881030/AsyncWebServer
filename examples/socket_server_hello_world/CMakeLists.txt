cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
/DevRes/Frameworks/boost_1_58_0/
../../src/socket
)

link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib/static)
link_libraries(boost_system asyncsocket)

set(SOURCE_FILES
main.cpp
)

add_executable(socket_server_hello_world ${SOURCE_FILES})