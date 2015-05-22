//
// Created by plter on 5/21/15.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>
#include "Data.h"
#include "SocketConnectionManager.h"
#include "OnSocketListener.h"

namespace aws {

    class SocketConnectionManager;
    class OnSocketListener;

    class Socket :public std::enable_shared_from_this<aws::Socket>{

    friend class ServerSocket;
    friend class SocketConnectionManager;

    private:
        Socket(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket);
        static std::shared_ptr<aws::Socket> create(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_);

    public:
        virtual ~Socket();

    public:
        std::shared_ptr<boost::asio::ip::tcp::socket> getAsioSocket();
        void async_write(std::shared_ptr<aws::Data> data, std::function<void (const boost::system::error_code &code, size_t t)> handler);
        void start();
        void stop();
        inline bool isClosed(){
            return !running_;
        }

    protected:
        void onClose();
        void onConnect();


    private:
        void do_receive();
        inline void setConnectionManager(std::shared_ptr<aws::SocketConnectionManager> manager){
            connection_manager_ = manager;
        }
        inline std::shared_ptr<aws::SocketConnectionManager> getConnectionManager(){
            return connection_manager_;
        }

    private:
        std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_;
        std::array<char ,1024> buffer_;
        std::shared_ptr<aws::SocketConnectionManager> connection_manager_;
        bool running_;
        std::shared_ptr<aws::OnSocketListener> onSocketListener_;
    };
}
