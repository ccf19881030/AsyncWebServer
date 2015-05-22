//
// Created by plter on 5/22/15.
//

#pragma once

#include "Socket.h"
#include "ServerSocket.h"

namespace aws{

    class ServerSocket;

    class OnServerSocketListener{

    public:
        virtual void onAccept(std::shared_ptr<aws::ServerSocket> server,std::shared_ptr<aws::Socket> socket)=0;
    };
}
