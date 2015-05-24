//
// Created by plter on 5/20/15.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>
#include "boost/asio/io_service.hpp"
#include "Socket.h"
#include "SocketConnectionManager.h"

using boost::asio::ip::tcp;

namespace aws {

    class OnServerSocketListener;

    class ServerSocket: public std::enable_shared_from_this<aws::ServerSocket> {
    private:
        ServerSocket(int port);
    public:
        static std::shared_ptr<aws::ServerSocket> create(int port);
        virtual ~ServerSocket();

    public:

        void start();

        inline void setOnAcceptHandler(std::function<void(std::shared_ptr<aws::Socket> socket)> listener){
            onAcceptHandler_ = listener;
        }

        inline std::function<void(std::shared_ptr<aws::Socket> socket)> getOnServerSocketListener(){
            return onAcceptHandler_;
        }

    private:
        void do_accept();

    protected:
        void onAccept(std::shared_ptr<aws::Socket> socket);

    private:
        boost::asio::io_service ioservice_;
        tcp::acceptor acceptor_;
        std::function<void(std::shared_ptr<aws::Socket> socket)> onAcceptHandler_;
        std::shared_ptr<aws::SocketConnectionManager> connection_manager_;
    };

}
