//
// Created by plter on 5/20/15.
//

#ifndef PROJECT_SERVER_H
#define PROJECT_SERVER_H


#include "ServerSocket.h"
#include "RootContext.h"

namespace aws {
    class Server {
    public:
        Server(boost::shared_ptr<RootContext> context);
        virtual ~Server();

    private:
        boost::shared_ptr<aws::ServerSocket> asyncServer_;
    };
}


#endif //PROJECT_SERVER_H
