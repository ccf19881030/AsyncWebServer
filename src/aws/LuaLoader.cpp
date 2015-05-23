//
// Created by plter on 5/19/15.
//

#include <unistd.h>
#include "LuaLoader.h"
#include <boost/filesystem.hpp>

aws::LuaLoader::LuaLoader():context_() {
    luaState_ = luaL_newstate();
    luaL_openlibs(luaState_);
}

aws::LuaLoader::~LuaLoader() {
    lua_close(luaState_);
}

int aws::LuaLoader::getGlobalInt(const char * name) {
    lua_getglobal(luaState_, name);
    return lua_tointeger(luaState_, 1);;
}

bool aws::LuaLoader::loadFile(char *name) {
    if (boost::filesystem::exists(name)){
        luaL_dofile(luaState_,name);
        return true;
    } else{
        return false;
    }
}
