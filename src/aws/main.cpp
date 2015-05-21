
#include <ctime>
#include <iostream>
#include "ServerSocket.h"
#include "RootContext.h"
#include "Server.h"


int main(int argc, char ** argv)
{
    boost::shared_ptr<aws::RootContext> sc(new aws::RootContext());

    try
    {
        std::cout<<"Server will start at port "<<sc->getServerPort()<<"\n";
        boost::shared_ptr<aws::Server> server(new aws::Server(sc));
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}