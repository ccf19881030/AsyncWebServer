//
// Created by plter on 5/22/15.
//

#pragma once

#include <memory>
#include "Socket.h"

namespace aws{

    class Socket;
    class OnSocketListener{
    public:
        virtual void onConnect(std::shared_ptr<aws::Socket> sock_)=0;
        virtual void onClose(std::shared_ptr<aws::Socket> sock_)=0;
    };
}
