//
// Created by plter on 5/21/15.
//

#include <iostream>
#include "Socket.h"

aws::Socket::~Socket() {
    std::cout<<"Delete Socket Object\n";
}

aws::Socket::Socket(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket):running_(true) {
    asioSocket_ = asioSocket;

    do_receive();
}

std::shared_ptr<aws::Socket> aws::Socket::create(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_) {
    return std::shared_ptr<Socket>(new Socket(asioSocket_));
}

std::shared_ptr<boost::asio::ip::tcp::socket> aws::Socket::getAsioSocket() {
    return asioSocket_;
}


void aws::Socket::async_write(std::shared_ptr<aws::DataOutput> data,
                              std::function<void(const boost::system::error_code &code, size_t t)> handler) {
    asioSocket_->async_write_some(data->getAsioBuffer(),handler);
}

void aws::Socket::do_receive() {
    asioSocket_->async_read_some(boost::asio::buffer(buffer_),[this](boost::system::error_code error_code, std::size_t bytes_transferred){
        if (!error_code) {
            if (onReceiveHandler_){
                onReceiveHandler_(shared_from_this(),buffer_,bytes_transferred);
            }

            do_receive();
        } else{
            //disconnect
            if (running_) {
                running_ = false;
                onClose();
                connection_manager_->remove(shared_from_this());
            }
        }
    });
}

void aws::Socket::start() {
    running_ = true;
    onConnect();
    do_receive();
}

void aws::Socket::close() {
    asioSocket_->close();
}

void aws::Socket::onClose() {
    if (onCloseHandler_){
        onCloseHandler_(shared_from_this());
    }
}

void aws::Socket::onConnect() {
    if (onConnectHandler_){
        onConnectHandler_(shared_from_this());
    }
}
