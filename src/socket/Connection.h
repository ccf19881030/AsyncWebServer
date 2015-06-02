//
// Created by plter on 5/21/15.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>
#include "ConnectionManager.h"
#include "Buffer.h"

namespace aws {

    class ConnectionManager;
    class OnSocketListener;

    class Connection :public std::enable_shared_from_this<aws::Connection>{

    friend class ServerSocket;
    friend class ConnectionManager;

    public:
        typedef std::shared_ptr<aws::Connection> ConnectionPtr;
        typedef std::function<void(ConnectionPtr socket,aws::InputBuffer & buffer,std::size_t bytes_transferred)> OnReceiveHandler;

    private:
        Connection(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket);
        static std::shared_ptr<aws::Connection> create(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_);

    public:
        virtual ~Connection();

    public:
        std::shared_ptr<boost::asio::ip::tcp::socket> getAsioSocket();
        void start();
        void close();
        inline bool isClosed(){
            return !running_;
        }

    public://set/get functions
        inline void setConnectionManager(std::shared_ptr<aws::ConnectionManager> manager){
            connection_manager_ = manager;
        }
        inline std::shared_ptr<aws::ConnectionManager> getConnectionManager(){
            return connection_manager_;
        }
        inline void setOnCloseHandler(std::function<void(std::shared_ptr<aws::Connection> socket)> handler){
            onCloseHandler_ = handler;
        }
        inline std::function<void(std::shared_ptr<aws::Connection> socket)> getOnCloseHandler(){
            return onCloseHandler_;
        }
        inline void setOnConnectHandler(std::function<void(std::shared_ptr<aws::Connection> socket)> handler){
            onConnectHandler_ = handler;
        }
        inline std::function<void(std::shared_ptr<aws::Connection> socket)> getOnConnectHandler(){
            return onConnectHandler_;
        }
        inline void setOnReceiveHandler(OnReceiveHandler handler){
            onReceiveHandler_ = handler;
        }
        inline OnReceiveHandler getOnReceiveHandler(){
            return onReceiveHandler_;
        }

    protected:
        void onClose();
        void onConnect();


    private:
        void do_receive();


    private:
        std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_;
        aws::InputBuffer buffer_;
        std::shared_ptr<aws::ConnectionManager> connection_manager_;
        bool running_;
        std::function<void(ConnectionPtr socket)> onCloseHandler_;
        std::function<void(ConnectionPtr socket)> onConnectHandler_;
        OnReceiveHandler onReceiveHandler_;
    };
}
