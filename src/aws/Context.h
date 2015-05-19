//
// Created by plter on 5/19/15.
//

#ifndef ASYNCWEBSERVER_CONTEXT_H
#define ASYNCWEBSERVER_CONTEXT_H


#include <boost/smart_ptr/shared_ptr.hpp>
#include "LuaBridge.h"

class Context {

public:
    Context();
    virtual ~Context();

public:
    LuaBridge * getLuaBridge();

private:
    LuaBridge * luaBridge;
};


#endif //ASYNCWEBSERVER_CONTEXT_H
