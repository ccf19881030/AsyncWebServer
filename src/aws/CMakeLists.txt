cmake_minimum_required(VERSION 3.2)

project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/DevRes/Frameworks/boost_1_58_0 ../lua5_3/src ../socket)
link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib)
link_libraries(lua5_3 asyncsocket)

set(SOURCE_FILES
main.cpp
Context.cpp
LuaBridge.cpp
ServerContext.cpp
Server.cpp
)

add_executable(aws ${SOURCE_FILES})