//
// Created by plter on 5/22/15.
//


#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio::ip;
typedef std::shared_ptr<boost::asio::io_service> io_service_ptr;
typedef std::shared_ptr<tcp::acceptor> acceptor_ptr;
typedef std::shared_ptr<tcp::socket> socket_ptr;
typedef boost::system::error_code boost_errcode;

void start_accept(io_service_ptr io_service,acceptor_ptr acceptor){

    socket_ptr socket(new tcp::socket(*io_service));

    acceptor->async_accept(*socket,[socket,io_service,acceptor](const boost_errcode& error){
        if (!error){
            socket->async_write_some(boost::asio::buffer("Hello World\n"),[](const boost_errcode &code, size_t t){
                std::cout<<"Wrote to client\n";
            });
        }

        start_accept(io_service,acceptor);
    });
}


int main(){
    io_service_ptr io_service_(new boost::asio::io_service());
    acceptor_ptr acceptor_(new tcp::acceptor(*io_service_, tcp::endpoint(tcp::v4(), 6000)));
    start_accept(io_service_,acceptor_);
    io_service_ ->run();
    return 0;
}