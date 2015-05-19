cmake_minimum_required(VERSION 3.2)
project(AsyncWebServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(/DevRes/Frameworks/boost_1_58_0)
link_directories(/DevRes/Frameworks/boost_1_58_0/stage/lib)
link_libraries(boost_system)

set(SOURCE_FILES src/main.cpp
src/tcp_server.cpp
src/tcp_connection.cpp
src/Context.cpp
src/LuaBridge.cpp
src/ServerContext.cpp

# lua5_3 >>>>>>>>>>
src/lua5_3/src/lapi.c
src/lua5_3/src/lauxlib.c
src/lua5_3/src/lbaselib.c
src/lua5_3/src/lbitlib.c
src/lua5_3/src/lcode.c
src/lua5_3/src/lcorolib.c
src/lua5_3/src/lctype.c
src/lua5_3/src/ldblib.c
src/lua5_3/src/ldebug.c
src/lua5_3/src/ldo.c
src/lua5_3/src/ldump.c
src/lua5_3/src/lfunc.c
src/lua5_3/src/lgc.c
src/lua5_3/src/linit.c
src/lua5_3/src/liolib.c
src/lua5_3/src/llex.c
src/lua5_3/src/lutf8lib.c
src/lua5_3/src/lmathlib.c
src/lua5_3/src/lmem.c
src/lua5_3/src/loadlib.c
src/lua5_3/src/lobject.c
src/lua5_3/src/lopcodes.c
src/lua5_3/src/loslib.c
src/lua5_3/src/lparser.c
src/lua5_3/src/lstate.c
src/lua5_3/src/lstring.c
src/lua5_3/src/lstrlib.c
src/lua5_3/src/ltable.c
src/lua5_3/src/ltablib.c
src/lua5_3/src/ltm.c
src/lua5_3/src/lundump.c
src/lua5_3/src/lvm.c
src/lua5_3/src/lzio.c
# lua5_3 <<<<<<<<<<<
)

add_executable(AsyncWebServer ${SOURCE_FILES})