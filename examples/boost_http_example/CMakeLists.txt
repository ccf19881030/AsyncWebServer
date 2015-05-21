cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

include_directories(/DevRes/Frameworks/boost_1_58_0)
link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib)
link_libraries(boost_system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
connection.cpp
connection_manager.cpp
mime_types.cpp
reply.cpp
request_handler.cpp
request_parser.cpp
server.cpp
header.hpp
request.hpp )

add_executable(boost_http_server ${SOURCE_FILES})