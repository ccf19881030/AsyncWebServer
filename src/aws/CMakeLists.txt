cmake_minimum_required(VERSION 3.2)

project(AsyncWebServer)

include_directories(../lua5_3/src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(/DevRes/Frameworks/boost_1_58_0)
link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib)
link_libraries(boost_system lua5_3)

set(SOURCE_FILES
main.cpp
tcp_server.cpp
tcp_connection.cpp
Context.cpp
LuaBridge.cpp
ServerContext.cpp
)

add_executable(aws ${SOURCE_FILES})