//
// Created by plter on 5/21/15.
//

#include <iostream>
#include <Log.h>
#include "Connection.h"

aws::Connection::~Connection() {
    aws::Log::info("Delete Connection Object");
}

aws::Connection::Connection(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket):running_(true) {
    asioSocket_ = asioSocket;

    do_receive();
}

std::shared_ptr<aws::Connection> aws::Connection::create(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_) {
    return std::shared_ptr<Connection>(new Connection(asioSocket_));
}

std::shared_ptr<boost::asio::ip::tcp::socket> aws::Connection::getAsioSocket() {
    return asioSocket_;
}


void aws::Connection::do_receive() {
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

void aws::Connection::start() {
    running_ = true;
    onConnect();
    do_receive();
}

void aws::Connection::close() {
    asioSocket_->close();
}

void aws::Connection::onClose() {
    if (onCloseHandler_){
        onCloseHandler_(shared_from_this());
    }
}

void aws::Connection::onConnect() {
    if (onConnectHandler_){
        onConnectHandler_(shared_from_this());
    }
}
