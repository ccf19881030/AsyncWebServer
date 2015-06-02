#include <iostream>
#include "ConnectionManager.h"

namespace aws {
    ConnectionManager::ConnectionManager()
    {
    }

    void ConnectionManager::add(std::shared_ptr<aws::Connection> c)
    {
        c->setConnectionManager(shared_from_this());
        connections_.insert(c);
        c->start();
    }

    void ConnectionManager::remove(std::shared_ptr<aws::Connection> c)
    {
        connections_.erase(c);
    }
}
