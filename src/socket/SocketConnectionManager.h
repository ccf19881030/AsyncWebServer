//
// Created by plter on 5/22/15.
//

#pragma once

#include <set>
#include "Socket.h"

namespace aws {

    class Socket;

    class SocketConnectionManager:public std::enable_shared_from_this<aws::SocketConnectionManager>
    {
    public:
        SocketConnectionManager(const SocketConnectionManager&) = delete;
        SocketConnectionManager& operator=(const SocketConnectionManager&) = delete;

        SocketConnectionManager();

        void add(std::shared_ptr<aws::Socket> s);

        void remove(std::shared_ptr<aws::Socket> s);

        void remove_all();

    private:
        std::set<std::shared_ptr<aws::Socket>> connections_;
    };

}