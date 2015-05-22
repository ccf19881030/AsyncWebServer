//
// Created by plter on 5/22/15.
//

#pragma once

#include "Socket.h"

namespace aws{

    class OnServerSocketListener{

    public:
        virtual void onAccept(std::shared_ptr<aws::Socket> socket)=0;
    };
}
