//
// Created by plter on 5/20/15.
//

#include <boost/asio/write.hpp>
#include <iostream>
#include "AsyncServerSocket.h"



aws::AsyncServerSocket::AsyncServerSocket(int port):acceptor_(ioservice_,tcp::endpoint(tcp::v4(),port)) {
    start_accept();

    ioservice_.run();
}

aws::AsyncServerSocket::~AsyncServerSocket() {
}

void aws::AsyncServerSocket::start_accept() {

    aws::Connection::pointer new_connection =
            aws::Connection::create(acceptor_.get_io_service());

    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&aws::AsyncServerSocket::handle_accept, this, new_connection,
                                       boost::asio::placeholders::error));
}



void aws::AsyncServerSocket::handle_accept(aws::Connection::pointer new_connection,
                   const boost::system::error_code& error) {
    if (!error)
    {
        new_connection->start();
    }

    start_accept();
}
