cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

include_directories(/opt/boost_1_58_0)
link_directories(/opt/boost_1_58_0/stage/lib/static)
link_libraries(boost_system)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
)

add_executable(boost_asio_example ${SOURCE_FILES})