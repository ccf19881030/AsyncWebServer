//
// Created by plter on 5/22/15.
//


#include <OnServerSocketListener.h>
#include <ServerSocket.h>
#include <iostream>

class Listener:public aws::OnServerSocketListener{

public:

    virtual void onAccept(std::shared_ptr<aws::ServerSocket> server, std::shared_ptr<aws::Socket> socket) override;
};


int main(){

    std::shared_ptr<aws::ServerSocket> server = aws::ServerSocket::create(7000);
    server->setOnServerSocketListener(std::shared_ptr<aws::OnServerSocketListener>(new Listener()));
    std::cout<<"Server will start at port 7000\n";
    server->start();

    return 0;
}


void Listener::onAccept(std::shared_ptr<aws::ServerSocket> server, std::shared_ptr<aws::Socket> socket) {
    std::string message_ = "Hello World\n";

    socket->async_write(aws::DataOutput::dataFromString(message_),[socket](const boost::system::error_code &code, size_t t){
        std::cout<<"Write completed\n";

        socket->stop();
    });
}
