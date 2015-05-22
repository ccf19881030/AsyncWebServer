//
// Created by plter on 5/22/15.
//


#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio::ip;

void start_accept(std::shared_ptr<boost::asio::io_service> io_service,std::shared_ptr<tcp::acceptor> acceptor){
    std::shared_ptr<tcp::socket> socket(new tcp::socket(*io_service));

    acceptor->async_accept(*socket,[socket,io_service,acceptor](const boost::system::error_code& error){
        if (!error){
            socket->async_write_some(boost::asio::buffer("Hello World\n"),[](const boost::system::error_code &code, size_t t){
                std::cout<<"Wrote to client\n";
            });
        }

        start_accept(io_service,acceptor);
    });
}


int main(){
    std::shared_ptr<boost::asio::io_service> io_service_(new boost::asio::io_service());
    std::shared_ptr<tcp::acceptor> acceptor_(new tcp::acceptor(*io_service_, tcp::endpoint(tcp::v4(), 6000)));
    start_accept(io_service_,acceptor_);
    io_service_ ->run();
    return 0;
}