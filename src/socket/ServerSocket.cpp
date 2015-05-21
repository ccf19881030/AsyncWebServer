//
// Created by plter on 5/20/15.
//

#include <boost/asio/write.hpp>
#include <iostream>
#include "ServerSocket.h"



aws::ServerSocket::ServerSocket(int port):acceptor_(ioservice_,tcp::endpoint(tcp::v4(),port)) {
    start_accept();

    ioservice_.run();
}

aws::ServerSocket::~ServerSocket() {
}

void aws::ServerSocket::start_accept() {

    std::shared_ptr<boost::asio::ip::tcp::socket> socket_(new tcp::socket(ioservice_));

    acceptor_.async_accept(*socket_,[this,socket_](const boost::system::error_code& error){

        if (!error) {
            onAccept(Socket::create(socket_));
        }

        start_accept();
    });

}

void aws::ServerSocket::onAccept(std::shared_ptr<aws::Socket> socket) {
    std::string message_ = "Hello World\n";

    socket->async_write(boost::asio::buffer(message_),[](const boost::system::error_code &code, size_t t){
        std::cout<<"Write completed\n";
    });
}
