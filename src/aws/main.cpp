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
#include "AsyncServerSocket.h"
#include "ServerContext.h"
#include "Server.h"


int main(int argc, char ** argv)
{
    boost::shared_ptr<ServerContext> sc(new ServerContext());

    try
    {
        std::cout<<"Server will at port "<<sc->getServerPort()<<"\n";
        boost::shared_ptr<aws::Server> server(new aws::Server(sc));
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}