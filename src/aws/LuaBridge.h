//
// Created by plter on 5/19/15.
//

#ifndef ASYNCWEBSERVER_LUABRIDGE_H
#define ASYNCWEBSERVER_LUABRIDGE_H


#include <memory>
#include "lua.hpp"

namespace aws {

    class Context;
    class LuaBridge {

    public:
        LuaBridge(Context * context);
        virtual ~LuaBridge();

    public:
        int getGlobalInt(const char *name);

    private:
        lua_State *luaState_;
        Context * context_;
    };
}


#endif //ASYNCWEBSERVER_LUABRIDGE_H
