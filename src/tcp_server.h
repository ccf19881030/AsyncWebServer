//
// Created by plter on 5/19/15.
//

#ifndef ASYNCWEBSERVER_TCP_SERVER_H
#define ASYNCWEBSERVER_TCP_SERVER_H


#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "tcp_connection.h"
#include "ServerContext.h"

using boost::asio::ip::tcp;

class tcp_server
{
public:
  tcp_server(ServerContext & context, boost::asio::io_service& io_service)
          : acceptor_(io_service, tcp::endpoint(tcp::v4(), context.getServerPort()))
  {
    start_accept();
  }

private:
  void start_accept()
  {
    tcp_connection::pointer new_connection =
            tcp_connection::create(acceptor_.get_io_service());

    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&tcp_server::handle_accept, this, new_connection,
                                       boost::asio::placeholders::error));
  }

  void handle_accept(tcp_connection::pointer new_connection,
                     const boost::system::error_code& error)
  {
    if (!error)
    {
      new_connection->start();
    }

    start_accept();
  }

  tcp::acceptor acceptor_;
};


#endif //ASYNCWEBSERVER_TCP_SERVER_H
