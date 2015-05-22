//
// Created by plter on 5/22/15.
//


#include <OnServerSocketListener.h>
#include <ServerSocket.h>
#include <iostream>

class Listener:public aws::OnServerSocketListener{

public:
    virtual void onAccept(std::shared_ptr<aws::Socket> socket) override;
};


int main(){

    aws::ServerSocket server(7000);
    server.setOnServerSocketListener(std::shared_ptr<aws::OnServerSocketListener>(new Listener()));
    std::cout<<"Server will start at port 7000\n";
    server.start();

    return 0;
}

void Listener::onAccept(std::shared_ptr<aws::Socket> socket) {
    std::string message_ = "Hello World\n";

    socket->async_write(aws::Data::dataFromString(message_),[](const boost::system::error_code &code, size_t t){
        std::cout<<"Write completed\n";
    });
}
