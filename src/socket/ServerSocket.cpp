//
// Created by plter on 5/20/15.
//

#include <boost/asio/write.hpp>
#include <iostream>
#include "ServerSocket.h"



aws::ServerSocket::ServerSocket(int port):acceptor_(ioservice_,tcp::endpoint(tcp::v4(),port)) {
    start_accept();
}

aws::ServerSocket::~ServerSocket() {
}

void aws::ServerSocket::start_accept() {

    std::shared_ptr<boost::asio::ip::tcp::socket> socket_(new tcp::socket(ioservice_));

    acceptor_.async_accept(*socket_,[this,socket_](const boost::system::error_code& error){

        if (!error) {
            onAccept(aws::Socket::create(socket_));
        }

        start_accept();
    });
}

void aws::ServerSocket::start() {
    ioservice_.run();
}

void aws::ServerSocket::onAccept(std::shared_ptr<aws::Socket> socket) {
    if (onServerSocketListener_) {
        onServerSocketListener_->onAccept(socket);
    }
}
