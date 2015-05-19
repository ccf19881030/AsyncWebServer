//
// Created by plter on 5/19/15.
//

#include <stdio.h>
#include "Context.h"

Context::Context() {
    luaBridge = new LuaBridge();
}

Context::~Context() {
    delete luaBridge;
}

LuaBridge *Context::getLuaBridge() {
    return luaBridge;
}
