//
// Created by plter on 5/21/15.
//


#include <iostream>
#include <vector>
#include <Filter.h>
#include <SocketAcceptor.h>
#include <DataInputMessage.h>

class HelloWorldFilter:public aws::Filter{


public:
    virtual void onAccept(std::shared_ptr<aws::Socket> sock) override{
        sock->async_write(aws::DataOutput::dataFromString("Hello World\n"),[sock](const boost::system::error_code &code, size_t t){
            if (code){
                std::cout<<"Fail\n";
            } else{
                std::cout<<"Success\n";
            }

            sock->close();
        });
    };
};

int main() {

    auto acceptor = std::make_shared<aws::SocketAcceptor>(8000);
    std::cout << "Server will start at port 8000\n";
    acceptor->addFilter(std::make_shared<HelloWorldFilter>());
    acceptor->start();
    return 0;
}
