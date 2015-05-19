//
// Created by plter on 5/19/15.
//

#ifndef ASYNCWEBSERVER_LUABRIDGE_H
#define ASYNCWEBSERVER_LUABRIDGE_H


#include "lua.hpp"

class LuaBridge {

public:
    LuaBridge();
    virtual ~LuaBridge();

public:
    int getGlobalInt(const char * name);

private:
    lua_State * _luaState;
};


#endif //ASYNCWEBSERVER_LUABRIDGE_H
