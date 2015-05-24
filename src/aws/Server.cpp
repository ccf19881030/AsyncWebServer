//
// Created by plter on 5/23/15.
//

#include <iostream>
#include "Server.h"

aws::Server::Server() {
    config_file_loaded_ = false;
}

void aws::Server::exit(int code) {
    exit(code);
}

bool aws::Server::loadConfig(char *config_file_name) {
    if (luaLoader_.loadFile(config_file_name)){
        config_file_loaded_ = true;
        return true;
    } else{
        return false;
    }
}

int aws::Server::getServerPort() {
    return luaLoader_.getGlobalInt("server_port");
}

void aws::Server::start() {
    if (config_file_loaded_) {
        acceptor_ = std::make_shared<aws::SocketAcceptor>(getServerPort());
        acceptor_->start();
    } else{
        std::cerr<<"Please run loadConfig first\n";
    }
}
