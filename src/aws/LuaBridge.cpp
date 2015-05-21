//
// Created by plter on 5/19/15.
//

#include <unistd.h>
#include "LuaBridge.h"
#include <boost/filesystem.hpp>
#include <iostream>
#include "Context.h"

aws::LuaBridge::LuaBridge(Context * context):context_(context) {
    luaState_ = luaL_newstate();
    luaL_openlibs(luaState_);

    chdir("./conf");

    if (boost::filesystem::exists(boost::filesystem::path("server.lua"))) {
        luaL_dofile(luaState_, "server.lua");
    } else{
        std::cerr<<"Config file \"conf/server.lua\" not exists\n";
        context->exit(0);
    }
    chdir("../");
}

aws::LuaBridge::~LuaBridge() {
    lua_close(luaState_);
}

int aws::LuaBridge::getGlobalInt(const char * name) {
    lua_getglobal(luaState_, name);
    return lua_tointeger(luaState_, 1);;
}
