//
// Created by plter on 5/27/15.
//

#include <iostream>
#include "HttpFilter.h"
#include "InputBufferMessage.h"
#include "Request.hpp"
#include "RequestParser.hpp"
#include "Reply.hpp"

void aws::HttpFilter::onAccept(std::shared_ptr<aws::Connection> sock) {
    Filter::onAccept(sock);
}

void aws::HttpFilter::onReceive(std::shared_ptr<aws::Connection> sock, void * msg) {
    Filter::onReceive(sock, msg);

    auto m = (aws::InputBufferMessage *)msg;
//    std::cout<<m->getBuffer().data()<<"\n";

    aws::Request request_;
    aws::RequestParser parser_;
    auto data = m->getBuffer().data();
    auto result_ = parser_.parse(request_,data,data + (m->getBytesTransferred()));


    //TODO send msg to next filter
    sock->getAsioSocket()->async_write_some(aws::reply::stock_reply(aws::reply::ok).to_buffers(),[sock](boost::system::error_code err_code, std::size_t size){
        sock->close();
    });
}

void aws::HttpFilter::onClose(std::shared_ptr<aws::Connection> sock) {
    Filter::onClose(sock);
}
