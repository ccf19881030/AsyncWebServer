//
// Created by plter on 5/20/15.
//

#include "Server.h"

aws::Server::Server(boost::shared_ptr<RootContext> context)
        :asyncServer_(new ServerSocket(context->getServerPort())) {

}

aws::Server::~Server() {

}
