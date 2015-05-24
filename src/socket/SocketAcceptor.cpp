//
// Created by plter on 5/21/15.
//

#include <iostream>
#include "SocketAcceptor.h"
#include "DataInputMessage.h"

aws::SocketAcceptor::SocketAcceptor(int port):server_(aws::ServerSocket::create(port)) {
    server_->setOnAcceptHandler([this](std::shared_ptr<aws::Socket> socket){
        if (first_filter_) {
            first_filter_->onAccept(socket);

            socket->setOnCloseHandler([this](std::shared_ptr<aws::Socket> sock){
                first_filter_->onClose(sock);
            });
            socket->setOnReceiveHandler([this](aws::Socket::SocketPtr sock,std::array<char ,1024> & buffer){
                std::shared_ptr<aws::DataInputMessage> msg(new aws::DataInputMessage(buffer));
                first_filter_->onReceive(sock,msg);
            });
        }
    });
}

void aws::SocketAcceptor::addFilter(std::shared_ptr<Filter> filter) {

    if (!first_filter_){
        first_filter_=filter;
        last_filter_=filter;
    } else{
        last_filter_->setNext(filter);
        filter->setPre(last_filter_);
        last_filter_=filter;
    }
}

void aws::SocketAcceptor::start() {
    server_->start();
}
