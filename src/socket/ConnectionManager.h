//
// Created by plter on 5/22/15.
//

#pragma once

#include <set>
#include "Connection.h"

namespace aws {

    class Connection;

    class ConnectionManager :public std::enable_shared_from_this<aws::ConnectionManager>
    {
    public:
        ConnectionManager(const ConnectionManager &) = delete;
        ConnectionManager & operator=(const ConnectionManager &) = delete;

        ConnectionManager();

        void add(std::shared_ptr<aws::Connection> s);

        void remove(std::shared_ptr<aws::Connection> s);

        void remove_all();

    private:
        std::set<std::shared_ptr<aws::Connection>> connections_;
    };

}