//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <ctime>
#include <iostream>
#include <boost/asio.hpp>
#include "tcp_server.h"

using boost::asio::ip::tcp;


int main(int argc, char ** argv)
{
    boost::shared_ptr<ServerContext> sc(new ServerContext());

    try
    {
        boost::asio::io_service io_service;
        tcp_server server(*sc,io_service);
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}