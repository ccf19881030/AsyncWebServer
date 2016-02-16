
#include <iostream>
#include <boost/format.hpp>
#include "Server.h"


int main(int argc, char ** argv)
{

    if (argc<2){
        std::cerr<<"Usage:\naws server_config.lua\n";
        return 0;
    }

    aws::Server server;
    if (!server.loadConfig(argv[1])){
        std::cerr<<"Failed to load config file "<<argv[1]<<"\n";
        return 0;
    }

    std::cout<<"Server will start at port "<< server.getServerPort()<<"\n";
    server.start();

    return 0;
}