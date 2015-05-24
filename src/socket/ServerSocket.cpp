//
// Created by plter on 5/20/15.
//

#include <boost/asio/write.hpp>
#include <iostream>
#include "ServerSocket.h"



aws::ServerSocket::ServerSocket(int port):
        acceptor_(ioservice_,tcp::endpoint(tcp::v4(),port)),
        connection_manager_(new aws::SocketConnectionManager()) {
}

aws::ServerSocket::~ServerSocket() {
}

void aws::ServerSocket::do_accept() {

    std::shared_ptr<boost::asio::ip::tcp::socket> socket_(new tcp::socket(ioservice_));

    acceptor_.async_accept(*socket_,[this,socket_](const boost::system::error_code& error){

        if (!error) {
            auto sock_ = aws::Socket::create(socket_);
            connection_manager_->add(sock_);
            onAccept(sock_);
        }

        do_accept();
    });
}

void aws::ServerSocket::start() {
    do_accept();
    ioservice_.run();
}

void aws::ServerSocket::onAccept(std::shared_ptr<aws::Socket> socket) {
    if (onAcceptHandler_) {
        onAcceptHandler_(socket);
    }


}

std::shared_ptr<aws::ServerSocket> aws::ServerSocket::create(int port) {
    return std::shared_ptr<ServerSocket>(new aws::ServerSocket(port));
}
