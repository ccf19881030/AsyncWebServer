//
// Created by plter on 5/27/15.
//

#include <iostream>
#include "HttpFilter.h"
#include "DataInputMessage.h"

void aws::HttpFilter::onAccept(std::shared_ptr<aws::Socket> sock) {
    Filter::onAccept(sock);
}

void aws::HttpFilter::onReceive(std::shared_ptr<aws::Socket> sock, std::shared_ptr<aws::Message> msg) {
    Filter::onReceive(sock, msg);

    //TODO implement the http request

    auto m = std::static_pointer_cast<aws::DataInputMessage>(msg);
    std::cout<<m->getBuffer().data()<<"\n";

    sock->close();
}

void aws::HttpFilter::onClose(std::shared_ptr<aws::Socket> sock) {
    Filter::onClose(sock);
}
