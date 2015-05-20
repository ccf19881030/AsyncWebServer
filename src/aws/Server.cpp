//
// Created by plter on 5/20/15.
//

#include "Server.h"

aws::Server::Server(boost::shared_ptr<ServerContext> context)
        :asyncServer_(new AsyncServerSocket(context->getServerPort())) {

}

aws::Server::~Server() {

}
