//
// Created by plter on 5/21/15.
//

#pragma once

#include <boost/asio/ip/tcp.hpp>

namespace aws {

    class Socket {
    friend class ServerSocket;
    private:
        Socket(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket);
        static std::shared_ptr<aws::Socket> create(std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_);

    public:
        virtual ~Socket();

    public:
        std::shared_ptr<boost::asio::ip::tcp::socket> getAsioSocket();

        void async_write(boost::asio::const_buffers_1 buffers, std::function<void (const boost::system::error_code &code, size_t t)> handler);

    private:
        std::shared_ptr<boost::asio::ip::tcp::socket> asioSocket_;
    };
}
