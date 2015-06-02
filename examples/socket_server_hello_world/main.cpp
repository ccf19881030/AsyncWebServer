//
// Created by plter on 5/22/15.
//


#include <ServerSocket.h>
#include <iostream>

int main(){

    std::shared_ptr<aws::ServerSocket> server = aws::ServerSocket::create(7000);
    server->setOnAcceptHandler([](std::shared_ptr<aws::Connection> socket){

        socket->getAsioSocket()->async_write_some(boost::asio::buffer("HelloWorld\n"),[socket](const boost::system::error_code &code, size_t t){
            std::cout<<"Write completed\n";
            socket->close();
        });
    });

    std::cout<<"Server will start at port 7000\n";
    server->start();

    return 0;
}