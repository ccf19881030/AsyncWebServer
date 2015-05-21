//
// Created by plter on 5/19/15.
//

#pragma once

#include <memory>
#include <vector>
#include "LuaBridge.h"

namespace aws {

    class LuaBridge;
    class RootContext;
    class Context:public std::enable_shared_from_this<Context>{

    public:
        Context();
        virtual ~Context();

    public:
        LuaBridge * getLuaBridge();
        void exit(int code);

    private:
        LuaBridge * luaBridge_;

    };
}
