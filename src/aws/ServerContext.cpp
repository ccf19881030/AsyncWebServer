//
// Created by plter on 5/19/15.
//

#include "ServerContext.h"

int ServerContext::getServerPort() {
    return getLuaBridge()->getGlobalInt("server_port");
}
