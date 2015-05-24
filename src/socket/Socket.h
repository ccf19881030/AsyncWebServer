//
// Created by plter on 5/21/15.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>
#include "DataOutput.h"
#include "SocketConnectionManager.h"
#include "Buffer.h"

namespace aws {

    class SocketConnectionManager;
    class OnSocketListener;

    class Socket :public std::enable_shared_from_this<aws::Socket>{

    friend class ServerSocket;
    friend class SocketConnectionManager;

    public:
        typedef std::shared_ptr<aws::Socket> SocketPtr;
        typedef std::function<void(SocketPtr socket,aws::Buffer & buffer)> OnReceiveHandler;

    private:
        Socket(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket);
        static std::shared_ptr<aws::Socket> create(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_);

    public:
        virtual ~Socket();

    public:
        std::shared_ptr<boost::asio::ip::tcp::socket> getAsioSocket();
        void async_write(std::shared_ptr<aws::DataOutput> data, std::function<void (const boost::system::error_code &code, size_t t)> handler);
        void start();
        void close();
        inline bool isClosed(){
            return !running_;
        }

    public://set/get functions
        inline void setConnectionManager(std::shared_ptr<aws::SocketConnectionManager> manager){
            connection_manager_ = manager;
        }
        inline std::shared_ptr<aws::SocketConnectionManager> getConnectionManager(){
            return connection_manager_;
        }
        inline void setOnCloseHandler(std::function<void(std::shared_ptr<aws::Socket> socket)> handler){
            onCloseHandler_ = handler;
        }
        inline std::function<void(std::shared_ptr<aws::Socket> socket)> getOnCloseHandler(){
            return onCloseHandler_;
        }
        inline void setOnConnectHandler(std::function<void(std::shared_ptr<aws::Socket> socket)> handler){
            onConnectHandler_ = handler;
        }
        inline std::function<void(std::shared_ptr<aws::Socket> socket)> getOnConnectHandler(){
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
        aws::Buffer buffer_;
        std::shared_ptr<aws::SocketConnectionManager> connection_manager_;
        bool running_;
        std::function<void(SocketPtr socket)> onCloseHandler_;
        std::function<void(SocketPtr socket)> onConnectHandler_;
        OnReceiveHandler onReceiveHandler_;
    };
}
