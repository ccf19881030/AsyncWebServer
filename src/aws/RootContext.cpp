//
// Created by plter on 5/19/15.
//

#include "RootContext.h"

int aws::RootContext::getServerPort() {
    return getLuaBridge()->getGlobalInt("server_port");
}

aws::RootContext::RootContext() {

}
