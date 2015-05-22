cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

include_directories(/DevRes/Frameworks/boost_1_58_0)
link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib/static)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(boost_sharedptr ${SOURCE_FILES})