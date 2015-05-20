//
// Created by plter on 5/20/15.
//

#include "Connection.h"

aws::Connection::Connection(boost::asio::io_service &io_service): socket_(io_service) {

}

void aws::Connection::handle_write(const boost::system::error_code &code, size_t t) {

}

void aws::Connection::start() {
    message_ = "Hello World\n";

    boost::asio::async_write(socket_, boost::asio::buffer(message_),
                             boost::bind(&Connection::handle_write, shared_from_this(),
                                         boost::asio::placeholders::error,
                                         boost::asio::placeholders::bytes_transferred));

}

aws::Connection::pointer aws::Connection::create(boost::asio::io_service &io_service) {
    return pointer(new Connection(io_service));
}