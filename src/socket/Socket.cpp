//
// Created by plter on 5/21/15.
//

#include <iostream>
#include "Socket.h"

aws::Socket::~Socket() {
}

aws::Socket::Socket(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket) {
    asioSocket_ = asioSocket;


}

std::shared_ptr<aws::Socket> aws::Socket::create(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_) {
    return std::shared_ptr<Socket>(new Socket(asioSocket_));
}

std::shared_ptr<boost::asio::ip::tcp::socket> aws::Socket::getAsioSocket() {
    return asioSocket_;
}


void aws::Socket::async_write(std::shared_ptr<aws::Data> data,
                              std::function<void(const boost::system::error_code &code, size_t t)> handler) {
    asioSocket_->async_write_some(data->getAsioBuffer(),handler);
}
