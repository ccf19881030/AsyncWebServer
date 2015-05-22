//
// Created by plter on 5/20/15.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>
#include "boost/asio/io_service.hpp"
#include "Socket.h"
#include "OnServerSocketListener.h"

using boost::asio::ip::tcp;

namespace aws {

    class ServerSocket {
    public:
        ServerSocket(int port);
        virtual ~ServerSocket();

    public:

        void start();

        inline void setOnServerSocketListener(std::shared_ptr<aws::OnServerSocketListener> listener){
            onServerSocketListener_ = listener;
        }

        inline std::shared_ptr<aws::OnServerSocketListener> getOnServerSocketListener(){
            return onServerSocketListener_;
        }

    private:
        void start_accept();
        void onAccept(std::shared_ptr<aws::Socket> socket);

    private:
        boost::asio::io_service ioservice_;
        tcp::acceptor acceptor_;
        std::shared_ptr<aws::OnServerSocketListener> onServerSocketListener_;
    };

}
