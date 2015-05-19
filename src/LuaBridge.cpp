//
// Created by plter on 5/19/15.
//

#include <unistd.h>
#include "LuaBridge.h"

LuaBridge::LuaBridge() {
    _luaState = luaL_newstate();
    luaL_openlibs(_luaState);

    chdir("../conf");
    luaL_dofile(_luaState,"server.lua");
}

LuaBridge::~LuaBridge() {
    lua_close(_luaState);
}

int LuaBridge::getGlobalInt(const char * name) {
    lua_getglobal(_luaState,name);
    return lua_tointeger(_luaState,1);;
}
