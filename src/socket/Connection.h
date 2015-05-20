//
// Created by plter on 5/20/15.
//

#ifndef PROJECT_CONNECTION_H
#define PROJECT_CONNECTION_H

#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace aws {
    class Connection
            : public boost::enable_shared_from_this<Connection>
    {
    public:
        typedef boost::shared_ptr<Connection> pointer;

        static pointer create(boost::asio::io_service& io_service);


        inline tcp::socket& socket()
        {
            return socket_;
        }

        void start();

    private:
        Connection(boost::asio::io_service& io_service);

        void handle_write(const boost::system::error_code& /*error*/,
                          size_t /*bytes_transferred*/);

        tcp::socket socket_;
        std::string message_;
    };
}


#endif //PROJECT_CONNECTION_H
