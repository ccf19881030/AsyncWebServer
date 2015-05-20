//
// Created by plter on 5/20/15.
//

#ifndef PROJECT_ASYNCSOCKET_H
#define PROJECT_ASYNCSOCKET_H

#include <boost/asio/ip/tcp.hpp>
#include "boost/asio/io_service.hpp"
#include "Connection.h"

using boost::asio::ip::tcp;

namespace aws {

    class AsyncServerSocket {
    public:
        AsyncServerSocket(int port);
        virtual ~AsyncServerSocket();

    private:
        void start_accept();
        void handle_accept(aws::Connection::pointer new_connection,
                           const boost::system::error_code& error);

    private:
        boost::asio::io_service ioservice_;
        tcp::acceptor acceptor_;
    };

}


#endif //PROJECT_ASYNCSOCKET_H
