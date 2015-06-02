//
// Created by plter on 5/21/15.
//

#include <iostream>
#include "SocketAcceptor.h"
#include "InputBufferMessage.h"

aws::SocketAcceptor::SocketAcceptor(int port):server_(aws::ServerSocket::create(port)) {
    server_->setOnAcceptHandler([this](std::shared_ptr<aws::Connection> socket){
        if (first_filter_) {
            first_filter_->onAccept(socket);

            socket->setOnCloseHandler([this](std::shared_ptr<aws::Connection> sock){
                first_filter_->onClose(sock);
            });
            socket->setOnReceiveHandler([this](aws::Connection::ConnectionPtr sock,aws::InputBuffer & buffer,std::size_t bytes_transferred){
                aws::InputBufferMessage msg(buffer,bytes_transferred);
                first_filter_->onReceive(sock,&msg);
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
