//
// Created by plter on 5/20/15.
//

#ifndef PROJECT_SERVER_H
#define PROJECT_SERVER_H


#include <AsyncServerSocket.h>
#include "ServerContext.h"

namespace aws {
    class Server {
    public:
        Server(boost::shared_ptr<ServerContext> context);
        virtual ~Server();

    private:
        boost::shared_ptr<aws::AsyncServerSocket> asyncServer_;
    };
}


#endif //PROJECT_SERVER_H
