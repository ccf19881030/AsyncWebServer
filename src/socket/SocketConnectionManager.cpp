#include <iostream>
#include "SocketConnectionManager.h"

namespace aws {
    SocketConnectionManager::SocketConnectionManager()
    {
    }

    void SocketConnectionManager::add(std::shared_ptr<aws::Socket> c)
    {
        c->setConnectionManager(shared_from_this());
        connections_.insert(c);
        c->start();
    }

    void SocketConnectionManager::remove(std::shared_ptr<aws::Socket> c)
    {
        connections_.erase(c);
    }
}
