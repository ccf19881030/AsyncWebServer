//
// Created by plter on 5/19/15.
//

#include <stdio.h>
#include "Context.h"


aws::Context::Context() {
    luaBridge_ = new LuaBridge(this);
}

aws::Context::~Context() {
    delete luaBridge_;

}

aws::LuaBridge * aws::Context::getLuaBridge() {
    return luaBridge_;
}

void aws::Context::exit(int code) {
    exit(code);
}
