//
// Created by plter on 5/20/15.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>
#include "boost/asio/io_service.hpp"
#include "Socket.h"

using boost::asio::ip::tcp;

namespace aws {

    class ServerSocket {
    public:
        ServerSocket(int port);
        virtual ~ServerSocket();

    public:
        virtual void onAccept(std::shared_ptr<aws::Socket> socket);

    private:
        void start_accept();

    private:
        boost::asio::io_service ioservice_;
        tcp::acceptor acceptor_;
    };

}
